public class Food extends Item {
	private double heals = 0;

	public Food(String name, double weight, double heals) {
		super(name, weight);
		this.heals = heals;
	}

	@Override
	public double getHeals() {
		return heals;
	}

	@Override
	public String toString() {
		String message = super.toString() + "\n";
		message += "Heals: " + heals;
		return message;
	}
}
