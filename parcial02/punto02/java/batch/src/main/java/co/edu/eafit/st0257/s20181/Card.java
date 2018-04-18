package co.edu.eafit.st0257.s20181;

public class Card {
   private static int nro = 0;
   private int nCard;
   public Card() {
      nCard = Card.nro++;
   }
   public String toString() {
      return "Card: " + nCard;
   }
}
