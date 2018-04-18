
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/**
*
* @author Michael J. Reale
*/
public class Assign07 {
    public static void TEST_FUNCTIONS() {
     Map m = new Map(2,3);

     Drawable d = new Orc(0,1,100);
     d.drawToMap(null);
     d.drawToMap(m);

     Drawable s = new Spider(1,0,100);
     s.drawToMap(null);
     s.drawToMap(m);

     System.out.println("Test Map 1: " + m.getRows() + " rows, " + m.getColumns() + " cols");
     m.draw();

     Map m2 = new Map(2,3);

     Drawable e = new Orc(-1,0,100);
     e.drawToMap(m2);

     Drawable f = new Orc(0,-1,100);
     f.drawToMap(m2);

     Drawable g = new Orc(3,0,100);
     g.drawToMap(m2);

     Drawable h = new Orc(0,2,100);
     h.drawToMap(m2);

     System.out.println("Test Map 2: " + m2.getRows() + " rows, " + m2.getColumns() + " cols");
     m2.draw();
     m2.setMapLocation(2,1,'#');
     System.out.println("Test Map 2 AFTER:");
     m2.draw();

     Map m3 = new Map();
     System.out.println("Test Map 3: " + m3.getRows() + " rows, " + m3.getColumns() + " cols");
     m3.draw();

     Monster mon1 = new Orc(1,2,3);
     System.out.println("Monster 1: " + mon1.getX() + " " + mon1.getY() + " " + mon1.getHealth());
     mon1.setX(4);
     mon1.setY(5);
     mon1.setHealth(6);
     System.out.println("Monster 1 AFTER: " + mon1.getX() + " " + mon1.getY() + " " + mon1.getHealth());

     Monster mon2 = new Spider(-1,-2,-3);
     System.out.println("Monster 2: " + mon2.getX() + " " + mon2.getY() + " " + mon2.getHealth());
     mon2.setX(-4);
     mon2.setY(-5);
     mon2.setHealth(-6);
     System.out.println("Monster 2 AFTER: " + mon2.getX() + " " + mon2.getY() + " " + mon2.getHealth());

     Monster mon3 = new Orc();
     System.out.println("Monster 3: " + mon3.getX() + " " + mon3.getY() + " " + mon3.getHealth());

     Monster mon4 = new Spider();
     System.out.println("Monster 4: " + mon4.getX() + " " + mon4.getY() + " " + mon4.getHealth());

     Scanner testInput = new Scanner("79    8    \n    945   ");
     Monster mon5 = new Orc();
     try {
         mon5.load(testInput);
         System.out.println("Monster 5: " + mon5.getX() + " " + mon5.getY() + " " + mon5.getHealth());
     }
     catch(Exception ex) {
         ex.printStackTrace();
     }
    }

    public static void main(String [] args) {

        System.out.println("TEST CASES:");
        TEST_FUNCTIONS();

        System.out.println("MAIN PROGRAM:");

        try {
            Scanner inputUser = new Scanner(System.in);
            System.out.println("Enter level number");
            String levelName = inputUser.next();

            Scanner mapFile = new Scanner(new File("Map" + levelName + ".txt"));
            Map baseMap = new Map();
            baseMap.load(mapFile);

            System.out.println("Map has " + baseMap.getRows() + " rows and " + baseMap.getColumns() + " columns.");

            Scanner inputMonsters = new Scanner(new File("Monsters" + levelName + ".txt"));

            int numMonsters = inputMonsters.nextInt();
            ArrayList<Monster> allMonsters = new ArrayList<Monster>();
            for(int i = 0; i < numMonsters; i++) {
                String typeMonster = inputMonsters.next();

                Monster m = null;

                switch(typeMonster) {
                    case "Orc":
                    m = new Orc();
                    break;
                    case "Spider":
                    m = new Spider();
                    break;
                    default:
                    break;
                }

                if(m != null) {
                    m.load(inputMonsters);
                    allMonsters.add(m);
                }
            }

            for(int i = 0; i < allMonsters.size(); i++) {
                allMonsters.get(i).drawToMap(baseMap);
            }

            baseMap.draw();
        }
        catch(Exception e) {
            System.err.println("Game error");
            e.printStackTrace();
        }
    }
}
