import java.util.Scanner;

public class Assign05 {
	public static void main(String[] args) {
		Player player = new Player(3,3);

		Scanner input = new Scanner(System.in);

		boolean run = true;
		while (run) {
			input.reset();
			System.out.println("Enter item name and weight: ");
			String name = input.next();
			if (name.equalsIgnoreCase("None")) {
				break;
			}
			double weight = input.nextDouble();	

			input.reset();
			System.out.println("Is the item food? [Y/N]");
			String isFood = input.next();
			
			if (isFood.equalsIgnoreCase("Y")) {
				System.out.println("What is the item's healing power?");
				double heals = input.nextDouble();
				Food food = new Food(name, weight, heals);
				player.addItem(food);
			}
			else {
				Item item = new Item(name, weight);
				player.addItem(item);	
			}
			input.reset();
		}
		player.printInventory();

		System.out.println("Choose an item (integer): ");
		int itemToUse = input.nextInt();

		player.useItem(itemToUse);
		
		input.close();
		
	}
}

