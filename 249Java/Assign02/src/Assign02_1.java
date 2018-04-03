import java.util.Scanner;

public class Assign02_1 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        double a = input.nextDouble();
        double b = input.nextDouble();
        double c = input.nextDouble();
        double d = input.nextDouble();
        double e = input.nextDouble();
        double f = input.nextDouble();

        double x = 0.0;
        x = ((e*d) - (b*f)) / ((a*d) - (b*c));

        System.out.println("" + x);
    }
}