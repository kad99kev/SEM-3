/*
 Experiment no.: 9
 Title: Using 2D array to present the arithmetic operations on a matrix.
 Name: Kevlyn Kadamala
 Roll No.: 8340
 */

import java.util.Scanner;

class Matrix
{
	int [][]a;
	int r,c,sum;
	Scanner n=new  Scanner(System.in);
	Matrix()
	{
		a=new int[3][3];
		r=c=3;
	}
	
	Matrix(int x, int y)
	{
		r=x;
		c=y;
		a=new int[r][c];
	}
	
	void Read() //Method to read matrix values
	{
		System.out.println("Enter values");
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				a[i][j]=n.nextInt();
			}
		}
	}

	void Display() //Method to display matrix
	{
		System.out.println("Matrix is");
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				System.out.print(a[i][j]+" ");
			}
			System.out.print("\n");
		}
	}

	void add(Matrix l, Matrix m) //Method to add matrix
	{
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				a[i][j]=l.a[i][j]+m.a[i][j];
			}
		}
	}
	
	void Multi(Matrix l, Matrix m) //Method to multiply matrix
	{
			a=new int[l.r][m.c];
			for(int i=0; i<l.r; i++)
			{
				for(int j=0; j<m.c; j++)
				{
					sum=0;
					for(int k=0; k<l.c; k++)
					{
						sum=sum+l.a[i][k]*m.a[k][j];
					}
					a[i][j]=sum;
				}
			}
		
	}
}


public class matMult
{
	public static void main(String[]args)
	{
		Matrix m1=new Matrix(2,2);
		m1.Read();
		m1.Display();
		Matrix m2=new Matrix(2,2);
		m2.Read();
		m2.Display();
		Matrix m3=new Matrix(m1.r,m2.c);
		if(m1.c!=m2.r)
		{
			System.out.println("Matrix cannot be multiplied");
		}
		else
		{
			System.out.println("After Multiplication");
			m3.Multi(m1,m2);
			m3.Display();
		}
		if(m1.r!=m2.r && m1.c!=m2.c) //Condition of matrix multiplication
		{
			System.out.println("Matrix cannot be added");
		}
		else
		{
			System.out.println("After addition");
			m3.add(m1,m2);
			m3.Display();
		}
	}
}

/*
 OUTPUT:
 
Enter values
1
2
3
4
Matrix is
1 2 
3 4 
Enter values
5
6
7
8
Matrix is
5 6 
7 8 
After Multiplication
Matrix is
19 22 
43 50 
After addition
Matrix is
6 8 
10 12 
*/
