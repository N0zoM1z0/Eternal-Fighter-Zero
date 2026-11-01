// Bounded read-only function queries; output remains private analyst evidence.
//@category EFZ

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HexFormat;
import java.util.List;

public class EFZQueryFunction extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 4) throw new IllegalArgumentException("expected OUTPUT OP ADDRESS LIMIT");
        String operation = args[1];
        Address address = toAddr(args[2]);
        int limit = Integer.parseInt(args[3]);
        if (limit < 1 || limit > 10000) throw new IllegalArgumentException("invalid query limit");
        Function function = getFunctionContaining(address);
        if (function == null && !operation.equals("xrefs"))
            throw new IllegalArgumentException("no analyzed function at " + address);
        try (BufferedWriter output = Files.newBufferedWriter(Path.of(args[0]), StandardCharsets.UTF_8)) {
            output.write("# Provisional static Ghidra evidence; boundaries/types are unreviewed.\n");
            output.write("# target_sha256=" + currentProgram.getExecutableSHA256() + "\n");
            if (function != null) {
                output.write("function=" + function.getName(true) + " entry=" + function.getEntryPoint() +
                    " body_addresses=" + function.getBody().getNumAddresses() + "\n");
                output.write("signature=" + function.getSignature().getPrototypeString() + "\n");
            }
            if (operation.equals("decompile")) {
                if (!function.getEntryPoint().equals(address))
                    throw new IllegalArgumentException("decompile requires an exact function entry");
                DecompInterface decompiler = new DecompInterface();
                try {
                    if (!decompiler.openProgram(currentProgram))
                        throw new IllegalStateException(decompiler.getLastMessage());
                    DecompileResults result = decompiler.decompileFunction(function, 120, monitor);
                    if (!result.decompileCompleted() || result.getDecompiledFunction() == null)
                        throw new IllegalStateException("decompile failed: " + result.getErrorMessage());
                    output.write(result.getDecompiledFunction().getC());
                } finally { decompiler.dispose(); }
            } else if (operation.equals("disasm")) {
                InstructionIterator instructions = currentProgram.getListing().getInstructions(function.getBody(), true);
                int count = 0;
                while (instructions.hasNext() && count < limit) {
                    monitor.checkCancelled();
                    Instruction instruction = instructions.next();
                    output.write(instruction.getAddress() + "  " + HexFormat.of().formatHex(instruction.getBytes()) +
                        "  " + instruction + "\n");
                    count++;
                }
                if (instructions.hasNext()) output.write("[truncated at instruction limit=" + limit + "]\n");
            } else if (operation.equals("function")) {
                output.write("body=" + function.getBody() + "\n");
                output.write("calling_convention=" + function.getCallingConventionName() + "\n");
                output.write("is_thunk=" + function.isThunk() + "\n");
            } else if (operation.equals("callers") || operation.equals("callees")) {
                List<Function> related = new ArrayList<>(operation.equals("callers") ?
                    function.getCallingFunctions(monitor) : function.getCalledFunctions(monitor));
                related.sort(Comparator.comparing(Function::getEntryPoint));
                for (Function candidate : related.subList(0, Math.min(limit, related.size())))
                    output.write(candidate.getEntryPoint() + " " + candidate.getName(true) + "\n");
                if (related.size() > limit) output.write("[truncated at function limit=" + limit + "]\n");
                output.write("count=" + related.size() + "; unresolved indirect calls may be absent\n");
            } else if (operation.equals("xrefs")) {
                ReferenceIterator references = currentProgram.getReferenceManager().getReferencesTo(address);
                int count = 0;
                while (references.hasNext() && count < limit) {
                    monitor.checkCancelled();
                    Reference reference = references.next();
                    output.write(reference.getFromAddress() + " -> " + reference.getToAddress() + " " +
                        reference.getReferenceType() + "\n");
                    count++;
                }
                if (references.hasNext()) output.write("[truncated at reference limit=" + limit + "]\n");
            } else if (operation.equals("refs")) {
                InstructionIterator instructions = currentProgram.getListing().getInstructions(function.getBody(), true);
                int count = 0;
                boolean truncated = false;
                while (instructions.hasNext()) {
                    monitor.checkCancelled();
                    for (Reference reference : instructions.next().getReferencesFrom()) {
                        if (count == limit) { truncated = true; break; }
                        output.write(reference.getFromAddress() + " -> " + reference.getToAddress() + " " +
                            reference.getReferenceType() + "\n");
                        count++;
                    }
                    if (truncated) break;
                }
                if (truncated) output.write("[truncated at reference limit=" + limit + "]\n");
            } else throw new IllegalArgumentException("unsupported query operation");
        }
        println("EFZ_GHIDRA_QUERY_COMPLETE_V1:" + operation);
    }
}
