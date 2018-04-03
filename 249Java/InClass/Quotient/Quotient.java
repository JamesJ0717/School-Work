import java.util.Scanner;

public class Quotient{
	public static int quotient(int num1, int num2){
		return num1/num2;
	}

	public static void main(String[] args) {
		System.out.println("Enter numbers: ");
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		int c = quotient(a,b);

		System.out.println("Answer is " + c);
	}
}