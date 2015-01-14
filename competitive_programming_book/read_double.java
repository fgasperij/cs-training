import java.util.Scanner;
import java.io.PrintStream;

class ExampleApp {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    Integer i = 5;
    while (i-- > 0) {
      double input = in.nextDouble();
      System.out.format("%7.3f", input);
    }
  }
}
