package co.edu.eafit.st0257.s20181;

class ProcessReader implements Runnable {
   private Util util;
   private InputBuffer inputBuffer;
      
   ProcessReader(InputBuffer inputBuffer) {
         
      this.inputBuffer = inputBuffer;
   }

   public void run() {
      while (true) {
         Card card = Util.readCard();
         if (card == null) break;
         inputBuffer.deployCard(card);
      }
   }
}

class ProcessExecuter implements Runnable {
   private InputBuffer inputBuffer;
   private OutputBuffer outputBuffer;

   ProcessExecuter(InputBuffer inputBuffer, OutputBuffer outputBuffer) {
         
      this.inputBuffer = inputBuffer;
      this.outputBuffer = outputBuffer;
   }

   public void run() {
      while (true){
         Card card = inputBuffer.fetchCard();
         if (card == null) break;
         Line line = Util.process(card);
         outputBuffer.deployLine(line);
      }
   }
}

class ProcessPrinter implements Runnable {
   private OutputBuffer outputBuffer;

   ProcessPrinter(OutputBuffer outputBuffer) {
         
      this.outputBuffer = outputBuffer;
   }

   public void run() {
      while (true) {
         Line line = outputBuffer.fetchLine();
         Util.print(line);
      }
   }
}

public class App
{   
   public static void main(String[] args) {

      final int N = 10;
      
      InputBuffer inputBuffer = new InputBuffer(N);
      OutputBuffer outputBuffer = new OutputBuffer(N);

      Thread tReader   = new Thread(new ProcessReader(inputBuffer));
      Thread tExecuter = new Thread(new ProcessExecuter(inputBuffer, outputBuffer));
      Thread tPrinter  = new Thread(new ProcessPrinter(outputBuffer));

      tReader.start();
      tExecuter.start();
      tPrinter.start();

      try {
         tReader.join();
         tExecuter.join();
         tPrinter.start();
      } catch (InterruptedException ie) { }
   }


}
