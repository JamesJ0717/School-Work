import java.util.Scanner;
import java.util.ArrayList;

public class allinone {
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

class Player{
	private int[] position = new int[2];
	private int health = 100;
	private ArrayList<Item> inventory = new ArrayList<>();

	public Weapon currentWeapon;

	public Player(int x, int y){
            position[0] = x;
            position[1] = y;
	}

	public int getX(){
		return position[0];
	}

	public int getY(){
		return position[1];
	}

	public int getHealth(){
		return health;
	}

	public Weapon getCurrentWeapon(){
                return currentWeapon;
	}

	public void setX(int x){
        }

	public void setY(int y){
	}

	public void setHealth(int health){
            this.health = health;
	}

	public void setCurrentWeapon(Weapon weapon){
                currentWeapon = weapon;
                //System.out.println(weapon);
	}
	public void addItem(Item item){
		inventory.add(item);
	}
	public boolean useItem(int index){
		if ((index <= inventory.size()) && (inventory.get(index) instanceof Food))
		{
			health += inventory.get(index).getHeals();
                        System.out.println("Current Health: " + health);
			inventory.remove(index);
		}
		else
		{
			System.out.println("Cannot use item.");
		}
		return true;
	}
	public void printInventory(){
		System.out.println("INVENTORY: ");
		for (Item q: inventory) {
			System.out.println("Item " + inventory.indexOf(q));
			System.out.println(q.toString() + "\n");	
		}
	}

}

class Item{

	private String name = " \n";
	private double weight = 0;

	public Item(){

	}
	public Item(String name, double weight){
		this.name = name;
		this. weight = weight;
	}
	public String getName(){
		return name;
	}
	public double getWeight(){
		return weight;
	}
        @Override
	public String toString(){
		String message = "Name: " + name + "\n";
		message += "Weight: " + weight;
		return message;
	}
        public double getHeals(){
            return 0.0;
        }
}

class Food extends Item{
	private double heals = 0;

	public Food(String name, double weight, double heals){
		super(name, weight);
		this.heals = heals;
	}
        @Override
	public double getHeals(){
		return heals;
	}
	@Override
	public String toString(){
		String message = super.toString() + "\n";
		message += "Heals: " + heals;
		return message;
	}
}

class Weapon{

    private String name;
    private int damage = 0;

    //constructor 
    public Weapon(String name, int damage) {
            this.name = name;
            this.damage = damage;
        
        }

    public String getName(){
            return name;
    }

    public int getDamage(){
            return damage;
    }

    public void setName(String name){
            
    }

    public void setDamage(int damage){

        }

    public static void printWeapon(Weapon weapon){
        if (weapon == null) {
                    System.out.println("No weapon");
                }
        else {
                    System.out.println(weapon.getName());
                }
    }
}