package co.eafit.dis.st0257.s20181.bridge;

class ProcessWestEast implements Runnable {
   private Bridge bridge;
   private int nCar;
   
   ProcessWestEast(Bridge bridge, int nCar) {
      this.bridge = bridge;
      this.nCar   = nCar;
   }

   public void run() {
      bridge.enterWest(nCar);
      assert bridge.getNCarsOnBridge() < 2;
      bridge.leaveEast(nCar);
   }
}

class ProcessEastWest implements Runnable {
   private Bridge bridge;
   private int nCar;
   
   ProcessEastWest(Bridge bridge, int nCar) {
      this.bridge = bridge;
      this.nCar   = nCar;
   }

   public void run() {
      bridge.enterEast(nCar);
      assert bridge.getNCarsOnBridge() < 2;
      bridge.leaveWest(nCar);
   }
}

public class App {
    public static void main( String[] args ) {
       Thread we[] = new Thread[Utils.MAX_THREADS];
       Thread ew[] = new Thread[Utils.MAX_THREADS];
       
       Bridge bridge = new Bridge();
       
       for (int i = 0, j = 0; i < Utils.MAX_THREADS; ++i) {
          we[i] = new Thread(new ProcessWestEast(bridge, j++));
          ew[i] = new Thread(new ProcessEastWest(bridge, j++));
          we[i].start();
          ew[i].start();
       }
       
       for (int i = 0; i < Utils.MAX_THREADS; ++i) {
          try {
             we[i].join();
             ew[i].join();
          } catch (InterruptedException ie) { }
       }
    }
}
