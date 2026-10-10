// Decompile all functions to <outdir>/<program>.c
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class DumpDecomp extends GhidraScript {
  public void run() throws Exception {
    String outDir = getScriptArgs()[0];
    DecompInterface di = new DecompInterface();
    di.openProgram(currentProgram);
    PrintWriter pw = new PrintWriter(new FileWriter(new File(outDir, currentProgram.getName() + ".c")));
    int n = 0, fail = 0;
    for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
      if (f.isExternal() || f.isThunk()) continue;
      DecompileResults r = di.decompileFunction(f, 60, monitor);
      n++;
      pw.println("// ==== " + f.getName() + " @ " + f.getEntryPoint() + " size=" + f.getBody().getNumAddresses());
      if (r != null && r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
      else { fail++; pw.println("// decompile FAILED: " + (r == null ? "" : r.getErrorMessage())); }
    }
    pw.close();
    println("DUMPED " + currentProgram.getName() + " functions=" + n + " failed=" + fail);
  }
}
