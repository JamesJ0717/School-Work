import java.util.Scanner;

public class Assign06_1 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    try {
      System.out.println("Please enter an expression: ");
      String expression = input.nextLine();
      Calculator.eval(expression);
    } catch (Exception e) {

    }
    input.close();
  }
}
