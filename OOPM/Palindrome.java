/*
Experiment no.: 11
Title:Write a program that compares two Strings using String and StringBuffer class.
Name: Kevlyn Kadamala
Roll No.:8340
*/

import java.util.*;

public class Palindrome
{
  	public static void main(String args[])
  	{	
		Scanner in = new Scanner(System.in);
		System.out.println("Enter a string: ");
		String str1 = in.next(); //enter one word				  
   		StringBuffer sb1 = new StringBuffer(str1);   //convert string object to stringbuffer
  		sb1.reverse(); //reverse mutable object
   		String str2 = sb1.toString(); //convet stringbuffer object to string

   		if(str1.equals(str2)) //object value equality
   		{ 
     			System.out.println("YES, " + str1 + " is Palindrome");
   		}
   		else
   		{
     			System.out.println("NO, " + str1 + " is not Palindrome");
   		}
 	}
}

/*
OUTPUT:
 
 Enter a string:
 palinilap
 YES, palinilap is Palindrome
 
 Enter a string:
 palindrome
 NO, palindrome is not Palindrome
*/
