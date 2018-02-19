import java.util.Scanner;

public class Assign03_2 {
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);

		System.out.println("Please enter the number of sides: ");
		int n = input.nextInt();

		System.out.println("Please enter the side length: ");
		double s = input.nextDouble();

		if(n<3) {
			System.out.println("ERROR: Number of sides must be >= 3!");
		}

		else {
			double area = 0.0;
			area = computeArea(n, s);
			System.out.println("" + area);
		}
	}
	public static double computeArea(int n, double s){

		double area = 0.0;
		area = (n*(Math.pow(s,2))) / ((4*Math.tan(Math.PI/n)));

		return area;
	}

}