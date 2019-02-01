/*
 Experiment no.: 20
 Title: User defined exceptions
 Name: Kevlyn Kadamala
 Roll No.: 8340
 */

import java.util.*;

class InvalidAgeException extends Exception
{

 	InvalidAgeException(){}

 	InvalidAgeException(String s)
	{
  		super(s); //assign name to Exception using super construct
 	}
 	public String toString()
 	{
  		return "Candidate is less than 18 year is not allowed to vote.";
 	}
}

public class ValidateCandidate
{

   static void validate(int age) throws InvalidAgeException //handling exception with throws clause
   {
     if(age < 18)
         throw new InvalidAgeException("Invalid Candidate>>>>");
     else
         System.out.println("welcome to vote");
   }
   
   public static void main(String args[]) //handling exception with try-catch block
   {
      try{
		Scanner in = new Scanner(System.in);
          System.out.println("Enter age of candidate");
		int age = in.nextInt(); 
       		validate(age);
      	}
	catch(InvalidAgeException e)
	{
         	System.out.println("Exception occured: "+e);
      	}
	catch(InputMismatchException e)
	{
        System.out.println("Age is integer value: "+e);
	}
	

      System.out.println("rest of the code...");
  }
}

/*
 OUTPUT:
 
Enter age of candidate
12
Exception occured: Candidate is less than 18 year is not allowed to vote.
rest of the code...

Enter age of candidate
as
Age is integer value: java.util.InputMismatchException
rest of the code...

Enter age of candidate
20
welcome to vote
rest of the code...
 */
