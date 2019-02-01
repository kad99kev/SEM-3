/*
 Experiment no.: 13
 Title: Create a digital and analog clock using single Inheritance
 Name: Kevlyn Kadamala
 Roll No.: 8340
 */

import java.util.*;

class Clock
{
    protected int hrs, mins, secs;
    
    Clock()
    {}
    
    Clock(int h, int m, int s)
    {
        hrs=h;
        mins=m;
        secs=s;
    }
    
    public String toString()
    {
        return hrs+":"+mins+":"+secs;
    }
}

class Digital extends Clock
{
    protected String title;
    
    Digital()
    {}
    
    Digital(int h, int m, int s)
    {
        super(h,m,s);
    }
    
    void assign()
    {   if(hrs>12)
        {
            hrs=hrs%12;
            title="pm";
        }
        else
            title="am";
    }
        
    public String toString()
    {
        return super.toString()+" "+title;
    }
}

public class DigitalClock
{
    public static void main(String[]args)
    {
        Clock c = new Clock(21,29,47);
        Digital dc=new Digital(21,29,47);
        dc.assign();
        System.out.println("Analog time is: "+c);
        System.out.println("Digital time is: "+dc);
    }
}

/*
 OUTPUT:
 
 Analog time is: 21:29:47
 Digital time is: 9:29:47 pm
 */
