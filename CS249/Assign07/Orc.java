public class Orc extends Monster{
    public Orc(){
    }
    public Orc(int x, int y, int health){
        super(x, y, health);
    }
    public void drawToMap(Map screen){
        if (screen == null) {
            return;
        }
        else {
            // At (x,y) print "o"
            screen.setMapLocation(getX(), getY(), 'o');
            return;
        }
    }
}
