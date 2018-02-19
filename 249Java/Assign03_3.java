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
}