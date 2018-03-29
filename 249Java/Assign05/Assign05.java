import java.util.Scanner;

public class Assign05 {
	public static void main(String[] args) {
		Player player = new Player(3,3);

		Scanner input = new Scanner(System.in);

		while (true) {
			System.out.println("Enter item name: ");
			String name = input.nextLine();
			if (name == null) {
				break;
			}
			System.out.println("Enter item weight: ");
			double weight = input.nextDouble();
			System.out.println("Is the item food?");
			String isFood = input.nextLine();
			if (isFood == "Y") {
				System.out.println("What is the item's healing power?");
				double heals = input.nextDouble();
				Food food = new Food(name, weight, heals);

			}
			else {
				Item item = new Item(name, weight);
				player.addItem(item);

			}
		}
		player.printInventory();
	}
}