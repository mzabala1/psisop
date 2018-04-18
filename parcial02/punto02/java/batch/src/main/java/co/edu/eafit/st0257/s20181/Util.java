package co.edu.eafit.st0257.s20181;

public class Util {
   static Card readCard() {
      return new Card();
   }

   static Line process(Card card) {
      return new Line(card);
   }

   static void print(Line line) {
      System.out.println(line);
   }
}
