package co.eafit.dis.st0257.s20181.bridge;

public class Bridge {
   private int nCarsOnBridge = 0;

   public Bridge() {
      this.nCarsOnBridge = 0;
   }

   private static void printCar(String place, int nCar) {
      System.out.println("nCar: " + nCar + place);
   }

   public void enterWest(int nCar) {
      printCar(" is entering by west", nCar);
      nCarsOnBridge++;
   }

   public void enterEast(int nCar) {
      printCar(" is entering by east", nCar);
      nCarsOnBridge--;
   }
   
   public void leaveWest(int nCar) {
      printCar(" is leaving by west", nCar);
      nCarsOnBridge--;
   }

   public void leaveEast(int nCar) {
      printCar(" is leaving by east", nCar);
      nCarsOnBridge--;
   }

   public int getNCarsOnBridge() {
      return nCarsOnBridge;
   }
}
