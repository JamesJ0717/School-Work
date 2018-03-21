public class Assign04{
	public static void main(String[] args) {
            Weapon sword = new Weapon("Common Sword", 50);
            Weapon coolSword = new Weapon("Glamdring, the Foe-Hammer", 1500);
            
            Player player = new Player(100, 100);
            
            Weapon.printWeapon(player.getCurrentWeapon());
            //System.out.println(player.getCurrentWeapon());
            
            player.setCurrentWeapon(sword);
            //System.out.println(player.getCurrentWeapon());
            Weapon.printWeapon(player.getCurrentWeapon());
            
            player.setCurrentWeapon(coolSword);
            //System.out.println(player.getCurrentWeapon());
            Weapon.printWeapon(player.getCurrentWeapon());
	}
}
