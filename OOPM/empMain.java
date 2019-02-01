/*
Experiment no.: 4
Title: Class employee with static var constructor
Name: Kevlyn Kadamala
Roll No.: 8340

*/
import java.util.*;
class employee
{
	int empno;
	String desig;
	double sal;
	static int count;
 		
	employee()
	{
		empno=100+(++count);
	}
  	void readData()
	{
		Scanner n = new Scanner(System.in);
		System.out.println("Enter designation");
  		desig=n.nextLine();
		System.out.println("Enter salary :");
		sal=n.nextDouble();	
	}
	void displayData()
	{	
		System.out.println("The no. of the employee: "+empno);
		System.out.println("The salary of the employee: "+sal);
		System.out.println("The designation of the employee: "+desig);
	}
	static int getCount()
	{
		return count;
	}
	static	void compare(employee [] er)
	{	
		int i;
		employee temp= new employee();
		for(i=0;i<5;i++)
		{	
			for(int j=0;j<5;j++)
			{
				if((er[j].desig.compareTo(er[i].desig))>0) //Sorts according to designation alphabetically
				{
					temp=er[i];
					er[i]=er[j];
					er[j]=temp;
				}
			}
		}
	}
}
 
public class empMain
{
	public static void main(String [] args)
	{ 	int r=1,i,a=0;
		employee [] er= new employee[5];
		for(i=0;i<5;i++)
		{
			er[i] = new employee();
			er[i].readData();
			System.out.println("No. of employees: "+employee.getCount());
		}
		employee.compare(er);
		for(i=0;i<5;i++)
		{
			er[i].displayData();
		}
	}
}
/*
OUTPUT:
 
 Enter designation
 Manager
 Enter salary :
 10000
 No. of employees: 1
 Enter designation
 Asst. Manager
 Enter salary :
 5000
 No. of employees: 2
 Enter designation
 Office Clerk
 Enter salary :
 2500
 No. of employees: 3
 Enter designation
 Office Clerk
 Enter salary :
 2000
 No. of employees: 4
 Enter designation
 Housekeeping
 Enter salary :
 500
 No. of employees: 5
 The no. of the employee: 102
 The salary of the employee: 5000.0
 The designation of the employee: Asst. Manager
 The no. of the employee: 105
 The salary of the employee: 500.0
 The designation of the employee: Housekeeping
 The no. of the employee: 101
 The salary of the employee: 10000.0
 The designation of the employee: Manager
 The no. of the employee: 104
 The salary of the employee: 2000.0
 The designation of the employee: Office Clerk
 The no. of the employee: 103
 The salary of the employee: 2500.0
 The designation of the employee: Office Clerk
*/
