/*
 Experiment no.: 8
 Title: Write a program to print the employee of an organization in ascending order of
 their salary
 Name: Kevlyn Kadamala
 Roll No.: 8340
 */

import java.util.Scanner;
class Employee
{
	int empno;
	static int count; //Static to count number of employees
	String design;
	double sal;
	Employee()
	{
		empno=100+ ++count; //Adds count to 100 for employee number
	}
	
	void readData()
	{
		Scanner des=new Scanner(System.in);
		System.out.println("Enter Designation");
		design=des.nextLine();
		System.out.println("Enter salary");
		sal=des.nextDouble();
	}
	
	void display()
	{
        System.out.println("Employee number:  "+empno);
        System.out.println("Designation:  "+design);
        System.out.println("Salary: "+sal);
	}
	
	static int getCount()
	{
		return count;
	}
}

public class EmployeeMain
{
	public static void main(String[]args)
	{
        Scanner in = new Scanner(System.in);
        System.out.println("Enter number of employees");
        int noemp=in.nextInt();
        Employee [] e=new Employee[noemp];
        for(int i=0; i<noemp; i++)
        {
            e[i]=new Employee();
            e[i].readData();
        }
        
        for(int i=0; i<noemp-1; i++)
        {
            for(int j=0; j<noemp-1; j++)
            {
                Employee temp;
                if(e[j].sal>e[j+1].sal) //Sorting according to salary
                {
                    temp=e[j];
                    e[j]=e[j+1];
                    e[j+1]=temp;
                }
            }
        }
        
        System.out.println("Employees in ascending order of salary are");
        for(int i=0; i<noemp; i++)
        {
            e[i].display();
        }
	}
}
/*
 OUTPUT:
 
 Enter number of employees
 3
 Enter Designation
 Manager
 Enter salary
 10000
 Enter Designation
 Office Clerk
 Enter salary
 1000
 Enter Designation
 Housekeeper
 Enter salary
 100
 Employees in ascending order of salary are
 Employee number:  103
 Designation:  Housekeeper
 Salary: 100.0
 Employee number:  102
 Designation:  Office Clerk
 Salary: 1000.0
 Employee number:  101
 Designation:  Manager
 Salary: 10000.0
 */

















	
