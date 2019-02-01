package object;
import java.util.*;

public class Rectangle
{
    protected int length, breadth;
    
    public Rectangle()
    {}
    public Rectangle(int length, int breadth)
    
    {
        this.length = length;
        this.breadth= breadth;
    }
    
    public int getArea()
    
    {
        return length*breadth;
    }
    
}
