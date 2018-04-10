/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Jimmy
 */
import java.util.Scanner;

public class TestMain {
    public static void main(String[] args) {
        System.out.println("War... war never changes.");

        Scanner input = new Scanner(System.in);

        String word = input.nextLine();
        word.toLowerCase();
        System.out.println(word);
    }
}
