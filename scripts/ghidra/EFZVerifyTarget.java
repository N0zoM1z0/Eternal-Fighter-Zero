// Verify imported identity, actual entrypoint and complete mapped section bytes.
//@category EFZ

import ghidra.app.util.headless.HeadlessScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressIterator;
import java.security.MessageDigest;
import java.util.HexFormat;

public class EFZVerifyTarget extends HeadlessScript {
    private void fail(String message) {
        setHeadlessContinuationOption(HeadlessContinuationOption.ABORT);
        throw new IllegalStateException(message);
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 8) fail("invalid target attestation arguments");
        int regions = Integer.parseInt(args[4]);
        if (regions < 1 || args.length != 5 + regions * 3)
            fail("invalid section attestation count");
        if (!args[0].equalsIgnoreCase(currentProgram.getExecutableSHA256()))
            fail("imported program SHA256 mismatch");
        if (!args[1].equals(currentProgram.getName()))
            fail("imported module name mismatch");
        if (currentProgram.getImageBase().getOffset() != Long.decode(args[2]))
            fail("imported image base mismatch");
        if (!currentProgram.getLanguageID().getIdAsString().equals("x86:LE:32:default"))
            fail("imported program language is not x86 PE32");
        if (!currentProgram.getCompilerSpec().getCompilerSpecID().getIdAsString().equals("windows"))
            fail("imported program compiler specification is not windows");
        Address entry = toAddr(args[3]);
        boolean entryPresent = false;
        AddressIterator entries = currentProgram.getSymbolTable().getExternalEntryPointIterator();
        while (entries.hasNext())
            if (entries.next().equals(entry)) entryPresent = true;
        if (!entryPresent || getFunctionContaining(entry) == null)
            fail("actual entrypoint or analyzed entry function missing");
        byte[] buffer = new byte[65536];
        for (int i = 0; i < regions; i++) {
            Address address = toAddr(args[5 + i * 3]);
            int remaining = Integer.parseInt(args[6 + i * 3]);
            String expected = args[7 + i * 3];
            if (remaining <= 0) fail("invalid section extent");
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            while (remaining > 0) {
                monitor.checkCancelled();
                int length = Math.min(remaining, buffer.length);
                int observed = currentProgram.getMemory().getBytes(address, buffer, 0, length);
                if (observed != length) fail("incomplete mapped section at " + address);
                digest.update(buffer, 0, length);
                address = address.add(length);
                remaining -= length;
            }
            if (!HexFormat.of().formatHex(digest.digest()).equalsIgnoreCase(expected))
                fail("mapped section hash mismatch at " + args[5 + i * 3]);
        }
        println("EFZ_GHIDRA_ATTESTATION_V1:" + args[0]);
        println("module=" + currentProgram.getName() + " entry=" + entry +
            " mapped_sections=" + regions);
    }
}
