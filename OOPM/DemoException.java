/*
 Experiment no.: 20
 Title: User defined exceptions
 Name:Mayank Mishra
 Roll No.:8348
 */
import java.lang.*;
import java.util.*;
import java.io.*;
class IllegalMarksException extends Exception
{
	int marks;
	IllegalMarksException(int marks)
	{
	this.marks=marks;
	}
	public String toString() //To Return String
	{
	return "IllegalMarksException "+marks;
	}
}
class DemoException
{
	public static int getMarks() throws IllegalMarksException,IOException	
	{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	int marks;
	System.out.print("Enter the marks :");
	marks=Integer.parseInt(br.readLine());
	if(marks < 0)
		throw new IllegalMarksException(marks);
	else
		return marks;
	}
    
	public static void main(String[] args)
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int rno,marks;
		try
		{
			System.out.println("Enter the Roll Number"); //Roll Number Input	
			rno=Integer.parseInt(br.readLine());
			marks=getMarks();
			System.out.println("Mark Sheet");
			System.out.println("Roll No : "+rno);
			System.out.println("Marks = "+marks);
			if(marks > 40)
				System.out.println("RESULT : PASS ");
			else
				System.out.println("RESULT : FAIL ");
		}	
		catch(IOException ioe)
		{		
			System.out.println("IO ERROR. EXITING");
		}
		catch(IllegalMarksException ime)
		{
			System.out.println("ILLEGAL MARKS ENTERED. EXITING\t"+ime);
		}
	}
}

/*
 OUTPUT:
 
 Enter the Roll Number
 8340
 Enter the marks :99
 Mark Sheet
 Roll No : 8340
 Marks = 99
 RESULT : PASS

 Enter the Roll Number
 8348
 Enter the marks :-72
 ILLEGAL MARKS ENTERED. EXITING    IllegalMarksException -72

 Enter the Roll Number
 8342
 Enter the marks :39
 Mark Sheet
 Roll No : 8342
 Marks = 39
 RESULT : FAIL
 */
