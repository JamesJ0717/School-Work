public class Weapon{
<<<<<<< HEAD:249Java/Assign05/Weapon.java
	private String name;
=======

        private String name;
>>>>>>> 240636de7eaaeb05269b4fa00d0d36a630435ba3:249Java/Assign05/src/Weapon.java
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