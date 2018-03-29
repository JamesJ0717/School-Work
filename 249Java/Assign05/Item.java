public class Item{

	private String name = "";
	private double weight = 0;

	public Item(){

	}
	public Item(String name, double weight){

	}
	public String getName(){
		return name;
	}
	public double getWeight(){
		return weight;
	}
	@Override
	public String toString(){
		String message = "Name: " + getName();
		message += "Weight: " + getWeight();
		return message;

	}

}