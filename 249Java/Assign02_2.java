import java.util.Scanner;

public class Assign02_2{
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);

		System.out.println("Please enter the number of sides: ");
		int n = input.nextInt();

		System.out.println("Please enter the side length: ");
		double s = input.nextDouble();

		if (n<3) {
			System.out.println("ERROR: Number of sides must be >= 3!");
			return;
		}
		else {
			double area = 0.0;
			area = (n*(Math.pow(s,2))) / ((4*Math.tan(Math.PI/n)));
			System.out.println(area);
		}
	}
}