import java.util.ArrayList;

public class Player{
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
	// public void addItem(Item item){
	// 	this.inventory += item;
	// }
	// public boolean useItem(int index){
	// 	if (index && inventory.get(index).instanceOf(Food)) {
	// 		Player.health += item.heals;
	// 	}
	// }

}