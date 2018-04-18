package co.edu.eafit.st0257.s20181;

public class Line {
   private static int nro = 0;
   private int nLine;
   public Line(Card card) {
      nLine = Line.nro++;
   }
   public String toString() {
      return "Line: " + nLine;
   }
}
