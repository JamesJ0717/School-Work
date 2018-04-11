import java.util.Scanner;
import java.io.PrintWriter;

public class Assign06_2 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        try {

            System.out.println("Please enter a file path or url: ");
            String path = input.nextLine();
            WordCountData data = WordCounter.count(path);

            PrintWriter output = new PrintWriter("output.txt");

            //System.out.println(path);
            System.out.println("Number of characters: " + data.getCharCnt());
            System.out.println("Number of words: " + data.getWordCnt());
            System.out.println("Number of lines: " + data.getLineCnt());

            output.println(path);
            output.println(data.getCharCnt());
            output.println(data.getWordCnt());
            output.println(data.getLineCnt());

            output.close();
        } catch (Exception e) {
            System.out.println("OH NO!");
            e.printStackTrace();
        } finally {

        }
        input.close();
    }

}
