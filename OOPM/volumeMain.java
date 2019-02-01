/*
Experiment no.:6
Title: Method overloading
Name: Kevlyn Kadamala
Roll No.:8340
*/

class volume
{
	int getVolume(int x)
	{
		return(x*x*x);		
	}
	double getVolume(double f)
	{
		return(3.142*4/3*f*f*f);
	}
	double getVolume(int r,int l)
	{
		return(3.142*r*r*l);
	}
	int getVolume(int x,int y, int z)
	{	
		return(x*y*z);	
	}
}
 
public class volumeMain
{
	public static void main(String [] args)
	{
		volume v1 = new volume();
		volume v2 = new volume();
		volume v3 = new volume();
		volume v4 = new volume();
		System.out.println("Volume of cube of side 3 is "+v1.getVolume(3));
		System.out.println("Volume of sphere of radius 5  is "+v2.getVolume(5.0));
		System.out.println("Volume of cylinder of radius 5 and height 6 is "+v3.getVolume(5,6));
		System.out.println("Volume of cuboid of dimension 5x4x6 is "+v4.getVolume(5,4,6));
	}
}
/*
OUTPUT:
 
 Volume of cube of side 3 is 27
 Volume of sphere of radius 5  is 523.6666666666666
 Volume of cylinder of radius 5 and height 6 is 471.29999999999995
 Volume of cuboid of dimension 5x4x6 is 120
*/
