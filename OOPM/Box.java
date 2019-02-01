package object;
import java.util.*;

public class Box extends Rectangle
{
    private int depth;
    
    public Box()
    {}
    public Box(int l, int b, int d)
    
    {
        super(l, b); //call parameterized constructor of Rectangle
        depth = d;
    }
    
    public double getVolume()
    
    {
        return (getArea()*breadth);
    }
    
}
