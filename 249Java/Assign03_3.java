<<<<<<< HEAD
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
=======
import java.util.Scanner;

public class Assign03_3 {
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		String userInput = "";

		do{
			System.out.println("Please enter a string.");
			userInput = input.nextLine();
			char[] userArray = userInput.toCharArray();
			String outputString = "";

			for (char letter: userArray) {
				if (Character.isDigit(letter)){
					outputString += "_";
				}
				else{
					outputString += letter;
				}
				
			}
			System.out.println(outputString);

		}
		while (!userInput.isEmpty());

	}
>>>>>>> 95b6c9a335ab7163c7d1f1c06235a8d6a4ec7efb
}