public class Weapon {

	private String name;
	private int damage = 0;

	//constructor
	public Weapon(String name, int damage) {
		this.name = name;
		this.damage = damage;

	}

	public String getName() {
		return name;
	}

	public int getDamage() {
		return damage;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setDamage(int damage) {
		this.damage = damage;
	}

	public static void printWeapon(Weapon weapon) {
		if (weapon == null) {
			System.out.println("No weapon");
		} else {
			System.out.println(weapon.getName());
		}
	}
}
