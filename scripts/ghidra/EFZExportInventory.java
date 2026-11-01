// Export provisional Ghidra candidates to a private file; never write ledgers.
//@category EFZ

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressRangeIterator;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;

public class EFZExportInventory extends GhidraScript {
    private static String csv(String value) {
        return "\"" + (value == null ? "" : value).replace("\"", "\"\"") + "\"";
    }
    private static String hex(long value) { return String.format("0x%08X", value); }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("expected OUTPUT");
        int count = 0;
        try (BufferedWriter output = Files.newBufferedWriter(Path.of(args[0]), StandardCharsets.UTF_8)) {
            output.write("address,size,span_end,body_size,current_name,is_thunk,calling_convention,signature,body_ranges,boundary_status,origin\n");
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext()) {
                monitor.checkCancelled();
                Function function = functions.next();
                if (function.isExternal()) continue;
                long start = function.getEntryPoint().getOffset();
                long end = function.getBody().getMaxAddress().getOffset();
                if (end < start) throw new IllegalStateException("invalid candidate extent");
                StringBuilder ranges = new StringBuilder();
                AddressRangeIterator iterator = function.getBody().getAddressRanges();
                while (iterator.hasNext()) {
                    AddressRange range = iterator.next();
                    if (ranges.length() > 0) ranges.append("|");
                    ranges.append(hex(range.getMinAddress().getOffset())).append(":")
                        .append(hex(range.getMaxAddress().getOffset()));
                }
                output.write(hex(start) + "," + (end - start + 1) + "," + hex(end) + "," +
                    function.getBody().getNumAddresses() + "," + csv(function.getName(true)) + "," +
                    function.isThunk() + "," + csv(function.getCallingConventionName()) + "," +
                    csv(function.getSignature().getPrototypeString()) + "," + csv(ranges.toString()) +
                    ",unreviewed,unknown\n");
                count++;
            }
        }
        if (count == 0) throw new IllegalStateException("no analyzed function candidates");
        println("EFZ_GHIDRA_INVENTORY_COMPLETE_V1 count=" + count);
    }
}
