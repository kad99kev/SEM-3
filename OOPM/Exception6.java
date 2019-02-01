/*
 Experiment no.: 19
 Title: Program to demonstrate try, catch, throw, throws and finally.
 Name: Kevlyn Kadamala
 Roll No.:8340
 */

import java.util.*;

class Point
{
	int x,y;
}

public class Exception6
{
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
        System.out.println("Enter choice: ");
		int choice = in.nextInt();
        try
        {
            while(true)
            {
                if(choice == 1)
                {
                    Point p=null;

                    System.out.println(p.x); //null pointer exception
                }
                else if(choice == 2)
                {
                    System.out.println("Enter a Number"); //if you enter number containing character
                    String s = in.next();
                    int i = Integer.parseInt(s);//NumberformatException
            
                }
                else if(choice == 3)
                {
                    int a[] = {1,2,3};
                    System.out.println(a[3]);//Array out of bounds exception
                    
                }
                else if(choice == 4)
                {
                    System.out.println("Enter two numbers");
                    int a = in.nextInt();
                    int b =in.nextInt();
                    System.out.println("Answer is "+a/b);
                }
                else
                {
                    break;
                }

            }
        }
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println(e);
		}
		catch(ArithmeticException e)
		{
			System.out.println(e);
		}
		catch(NullPointerException e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
		finally
		{
			System.out.println("Always executed");
		}

		System.out.println("Out of main");
	}
}

/*
 OUTPUT:
 
 Enter choice:
 1
 java.lang.NullPointerException
 Always executed
 Out of main
 
 Enter choice:
 2
 Enter a Number
 1
 Enter a Number
 2
 Enter a Number
 Test
 java.lang.NumberFormatException: For input string: "Test"
 Always executed
 Out of main
 
 Enter choice:
 3
 java.lang.ArrayIndexOutOfBoundsException: 3
 Always executed
 Out of main
 
 Enter choice:
 4
 Enter two numbers
 4
 2
 Answer is 2
 Enter two numbers
 4
 0
 java.lang.ArithmeticException: / by zero
 Always executed
 Out of main
*/
