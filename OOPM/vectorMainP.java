/*
Experiment no.: 18
Title: Implementation of packages
Name: Kevlyn Kadamala
Roll No.:8340
*/

package p2;
import p1.*;
import java.util.*;
//--------------------------------------------------------
package p1;
import java.util.Scanner;
public class StudentP
{
    int rollno,n;
    String name;
    public StudentP()
    {}
    public StudentP(int r, String n)
    {
        rollno = r;
        name = n;
    }
    
    public String toString()
    {
        return "["+rollno+","+name+"]";
    }
}
//the code above the comment goes in srccode named StudentP.java

//--------------------------------------------------------
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
//the code above the comment goes in srccode named PointP.java

//--------------------------------------------------------
public class vectorMainP
{
	public static void main(String [] args)
	{
		Vector v = new Vector();

		v.add(new Integer(10));
		v.add(new Float(10.5f));
		v.add("SE Computer");
		v.add(new PointP(2,3)); //add userdefined class objec
		v.add(1,new StudentP(10,"Shrek")); //at index 1 student object is inserted

		for(int i=0; i < v.size(); i++)
		{
			System.out.println((i+1)+" element is "+v.get(i));
		}
	}
}

/*
OUTPUT:

 javac -d . vectorMainP.java PointP.java StudentP.java
 java p2.vectorMainP p1.PointP p1.StudentP
 1 element is 10
 2 element is [10,Shrek]
 3 element is 10.5
 4 element is SE Computer
 5 element is [2,3]
*/
