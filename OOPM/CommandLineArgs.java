/*
 Experiment no.: 20
 Title: User defined exceptions
 Name: Kevlyn Kadamala
 Roll No.:8340
 */

import java.util.*;

class LessNumofArguments extends Exception //User defined exception
{
	LessNumofArguments(String s)
	{
		super(s);
	}
	public String toString()
	{
		return "You need to enter atleast 5 numbers";
	}
}

public class CommandLineArgs
{
	public static void main(String [] args)
	{
		try
		{
			if(args.length < 5) //Checks if number of inputs in cla is less than 5
				throw new LessNumofArguments("Few Arguments");
			else
			{
				double sum = 0.0;

				for(int i=0; i <args.length; i++)
				{
					sum = sum+Integer.parseInt(args[i]);
				}
			
				System.out.println("Avg is "+sum/args.length);
			}
		}
		catch(LessNumofArguments e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}

		System.out.println("End of Main");//because of try-catch, no abrupt termination of program.
	}
}


/*
 OUTPUT:
 
 java CommandLineArgs
 You need to enter atleast 5 numbers
 End of Main
 
java CommandLineArgs 1 4 2 5 6
 Avg is 3.6
 End of Main
 
java CommandLineArgs 1 4 2
 You need to enter atleast 5 numbers
 End of Main
 */
