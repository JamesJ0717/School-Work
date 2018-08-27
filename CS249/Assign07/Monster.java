import java.util.Scanner;

public abstract class Monster implements Loadable, Drawable{
    private int x = 0;
    private int y = 0;
    private int health = 100;

    protected Monster(){

    }
    protected Monster(int x, int y, int health){
        this.x = x;
        this.y = y;
        this.health = health;
    }

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getHealth() {
		return health;
	}

	public void setHealth(int health) {
		this.health = health;
	}

    Scanner input = new Scanner(System.in);
    public void load(Scanner input) throws Exception{
        x = input.nextInt();
        y = input.nextInt();
        health = input.nextInt();
    }

}
