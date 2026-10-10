import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
public class XrefDump extends GhidraScript {
  public void run() throws Exception {
    PrintWriter pw = new PrintWriter(new FileWriter(getScriptArgs()[0]));
    Listing L = currentProgram.getListing();
    for (Symbol s : currentProgram.getSymbolTable().getExternalSymbols()) {
      if (!s.getName().startsWith("_SV")) continue;
      java.util.List<Reference> refs = new java.util.ArrayList<>();
      for (Reference r : s.getReferences()) refs.add(r);
      // thunks / IAT pointers
      for (Reference r : refs) {
        Address a = r.getFromAddress();
        for (Reference r2 : getReferencesTo(a)) refs2(pw, L, s.getName(), r2.getFromAddress());
        refs2(pw, L, s.getName(), a);
      }
    }
    pw.close();
  }
  void refs2(PrintWriter pw, Listing L, String name, Address a) {
    Instruction ins = L.getInstructionAt(a);
    if (ins == null) return; if (!ins.getFlowType().isCall()) { Instruction q=ins; for(int k=0;k<40&&q!=null;k++){ q=q.getNext(); if(q!=null && q.getFlowType().isCall() && q.toString().startsWith("CALL E")) { refs2(pw,L,name+"(via reg "+ins+")",q.getAddress()); } } return; }
    Function f = getFunctionContaining(a);
    pw.println("== " + name + " called at " + a + " in " + (f==null?"?":f.getName()));
    Instruction p = ins; java.util.LinkedList<String> lines = new java.util.LinkedList<>();
    for (int i=0;i<14 && p!=null;i++){ lines.addFirst("   " + p.getAddress()+"  "+p); p=p.getPrevious(); }
    for (String l: lines) pw.println(l);
  }
}
