public class Spider extends Monster{
    public Spider(){

    }
    public Spider(int x, int y, int health){
        super(x, y, health);
    }
    public void drawToMap(Map screen){
        if(screen == null){
            return;
        }
        else {
            // At (x,y) print "s"
            screen.setMapLocation(getX(), getY(), 's');
            return;
        }
    }
}
