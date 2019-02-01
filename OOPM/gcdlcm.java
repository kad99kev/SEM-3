/*
Experiment no.: 2
Title: program to find the greatest common divisor and the lowest common multiple of two numbers
Name: Kevlyn Kadamala
Roll No.:8340
*/

import java.util.Scanner;

public class gcdlcm
{
	public static void main(String [] args)
     	{ 
   		int r,l,x,y; 		
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the numbers to compute: ");
		x=in.nextInt();
		y=in.nextInt();
		r=gcd(x,y);   //same class
		l=computelcm.lcm(x,y);  //different class
		System.out.println("The final value of GCD is "+r+" and LCM is "+l);
	}
    
	public static int gcd(int a,int b)
	{
		while(a!=b)
		{
			if(a>b)
			a-=b;
			if(b>a)
			b-=a;
		}
		return a;
  	}	
}
class computelcm
{
	public static int lcm(int a, int b)
	{
		return (a*b/(gcdlcm.gcd(a,b)));
	}
}

/*
OUTPUT:

 Enter the numbers to compute:
 21
 18
 The final value of GCD is 3 and LCM is 126
*/





