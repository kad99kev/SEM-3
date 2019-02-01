/*
Experiment no.:5
Title:power function having recursion and static method
Name:Kevlyn Kadamala
Roll No.:8340
*/

import java.util.Scanner;
 class Power
{
	public static void main(String [] args)
	{	int x,n;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the number and its power in the respective order:");
 		x=in.nextInt();
		n=in.nextInt();
		System.out.println("Result is : "+pow(x,n));
				
	}
    static int pow(int x,int n)
	{   
	    if(n==0)
            return 1;
		else if(n==1)
            return x;
		else if(n>1)
            return(x*pow(x,n-1));
		else
            System.out.println("Error");
		return -1;
	}
}

/*
OUTPUT:
 
 Enter the number and its power in the respective order:
 2
 4
 Result is : 16
*/
