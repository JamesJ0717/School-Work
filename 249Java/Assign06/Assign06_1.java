import java.util.Scanner;

public class Assign06_1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        try {
            System.out.println("Please enter an expression: ");
            String expression = input.nextLine();
            System.out.println(Calculator.eval(expression));
        } catch (InvalidExpressionException ex) {
            System.out.println("Invalid expression");
            ex.printStackTrace();
        }
        finally{
            input.close();
        }
    }
}
