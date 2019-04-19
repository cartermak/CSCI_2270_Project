public class HelloWorld {
   public native void displayHelloWorld();

   public static void main(String[] args) {
      System.load("/mnt/5932357A1CFE5229/OneDrive - University of Colorado at Boulder Office 365/OneDrive - UCB-O365/2019/CSCI 2270/Project/CSCI_2270_Project/Java experiementing/test.so");
      new HelloWorld().displayHelloWorld();
   }
}