import java.util.Scanner;

public class Map implements Loadable{
    private int mapRows = 0;
    private int mapCols = 0;
    private char[][] mapData;

    public Map(){
        this.mapRows = 0;
        this.mapCols = 0;
        this.mapData = new char[0][0];

    }
    public Map(int rows, int cols){
        this.mapRows = rows;
        this.mapCols = cols;
        this.mapData = new char[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mapData[i][j] = '.';
            }
        }
    }
    public int getRows(){
        return mapRows;
    }
    public int getColumns(){
        return mapCols;
    }
    public void draw(){
        for (int i=0;i<mapRows;i++) {
            for (int j=0;j<mapCols;j++) {
                System.out.print(mapData[i][j]);
            }
            System.out.println();
        }
    }
    public boolean setMapLocation(int x, int y, char c){
        if (x<0 || y<0) {
            return false;
        }
        else if(x<mapCols){
            if (y<mapRows) {
                mapData[y][x] = c;
                return true;
            }
            else {
                return false;
            }
        }
        else{
            return false;
        }
    }
    public void load(Scanner input) throws Exception{
        mapData = new char[0][0];
        mapRows = 0;
        mapCols = 0;

        mapRows = Integer.parseInt(input.nextLine());
        mapCols = Integer.parseInt(input.nextLine());

        mapData = new char[mapRows][mapCols];
        for (int i = 0; i<mapRows; i++) {
            String line = input.nextLine();
            for (int y = 0; y<mapCols; y++) {
                char x = line.charAt(y);
                mapData[i][y] = x;
            }
        }

        input.close();
    }
}
