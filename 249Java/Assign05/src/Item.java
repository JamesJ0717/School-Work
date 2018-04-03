public class Item{

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