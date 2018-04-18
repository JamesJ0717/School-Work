public class Orc extends Monster{
    public Orc(){

    }
    public Orc(int x, int y, int health){
        super(x, y, health);
    }
    void drawToMap(Map screen){
        if (screen == null) {
            return;
        }
        else {
            o.drawToMap(screen);
            return;
        }
    }
}
