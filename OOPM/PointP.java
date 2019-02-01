package p1;

public class PointP
{
    private int x;
    private int y;
    
    public PointP()
    {}
    public PointP(int x,int y)
    {
        this.x = x; //instance variable = local variable
        this.y = y;
    }
    
    public String toString()
    {
        return "["+x+","+y+"]";
    }
}
