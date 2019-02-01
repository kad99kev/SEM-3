/*
Experiment no.: 13 
Title: Implementation of single Inheritance
Name: Kevlyn Kadamala
Roll No.: 8340
*/

//single level inheritance
package client;
import object.*;
public class Rectbox
{   
	public static void main(String[] args)

    	{
		Rectangle r = new Rectangle(5, 5);

     		System.out.println("Area of Rectangle is "+r.getArea());

     		Box b = new Box(5, 5, 6);

     		System.out.println("volume of box is "+b.getVolume());

    	}

}
/save the above code in file RectBox.java
//--------------------------------------------------------
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

//save the above code in file Box.java
//--------------------------------------------------------
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
//save the above code in file Rectangle.java	
//--------------------------------------------------------


/*
OUTPUT:
 
 Area of Rectangle is 25
 volume of box is 125.0
*/
