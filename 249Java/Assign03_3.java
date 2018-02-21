import java.util.Scanner;

public class Assign03_3 {
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);

		String userInput = "";
		String outputString = "";

		do{
			System.out.println("Please enter a string.");
			userInput = input.nextLine();

			outputString = "";

			for (char c: userInput.toCharArray()) {

				if (Character.isDigit(c)) {
					outputString += "_";
				}				
				else {
					outputString += c;
				}
			}
			System.out.println(outputString);

		}
		while (userInput != "");

	}
}