/*
Experiment no.: 16
Title: Write a program that implements the stack interface.
Name: Kevlyn Kadamala
Roll No.: 8340
*/

import java.util.*;
//interface MyStack
interface MyStack
{
	void push(int ele);//by default all methods become public abstract
	int pop();
	int peek();
	void display();
	boolean isEmpty();
}
class StaticStack implements MyStack
{
	int [] a;//a is reference variable to array(container) of integers
  	int top;
  	
  	StaticStack()
  	{
  		top = -1;
  		a = new int[10];
  	}
	public void push(int ele)
	{
		if(top==a.length-1)
		{
			System.out.println("Stack is full");
		}
		else
			a[++top]=ele;
	}
	public int pop()
	{
		if(isEmpty()) // pop() method call isEmpty() method
		{		//i.e one instance method call other instance method
			System.out.println("Stack is empty");
			return -1;
		}
		else
			return a[top--];
	}
	public int peek()
	{
		if(isEmpty())
		{
			System.out.println("Stack is empty");
			return -1;
		}
		else
		return a[top];
	}
	public boolean isEmpty()
	{
		return (top==-1); //return true if top is equal to -1
	}
	public void display()
	{
		for(int i=top;i>=0;i--)
		{
			System.out.println(a[i]);
		}
	}
}

class Node
{
	int data;
	Node next;
	
	Node()
	{
		
		next = null;
	}
	
	Node(int d)
	{
		data = d;
		next = null;
	}
}


class DynStack implements MyStack
{
	Node top;
	public void push(int ele)
	{
		Node p = new Node(ele);
		if(top == null)
		{
			top = p;
		}
		else
		{
			p.next = top;
			top = p;
		}
			
	}
	
	public int peek()
	{
		if(top == null)
		{
			if(isEmpty()) 
			System.out.println("Stack is empty");
			return -1;
		}
		else 
		{
			return(top.data);
		}
	}
	
	public int pop()
	{
		if(top == null)
		{
			if(isEmpty()) 
			System.out.println("Stack is empty");
			return -1;
		}
		else
		{
			Node q = top;
			int x = q.data;
			top = top.next;
			//Node is freed automatically since no reference to it, garbage collected
			return x;
		}
	}
	
	public boolean isEmpty()
	{
		return top==null;
	}
	
	public void display()
	{
		Node q = top;
		while(q != null)
		{
			System.out.println(q.data);
			q = q.next;
		}
	}
}


public class StackDemo
{
	public static void main(String [] args)
	{	
		int n,r,l;
		Scanner in = new Scanner(System.in);
		MyStack s = new StaticStack(); //static stack
        System.out.println("For static stack");
		out :	while(true)
			{
                System.out.println("Enter\n1. To push\n2. To pop\n3. To peek\n4. To display\n5. To exit");
				System.out.println("Enter the choice");
				 n=in.nextInt();
				switch(n)
				{
					case 1:
						System.out.println("enter the element to be inserted");
						int b=in.nextInt();
						s.push(b);
					break;
					case 2:
						int a=s.pop();
						System.out.println("Popped element is "+a);
					break;
					case 3:
						r=s.peek();
						System.out.println("The element at the top of stack is "+r);
					break;
					case 4:
						System.out.println("The element in the  stack are: ");
					s.display();
					break;
					case 5:
					break out;
				}//switch ends
			}//while ends
			
		
				
		System.out.println("For dynamic stack");
		s = new DynStack(); //Dynamic stack
		out :	while(true)
			{
                System.out.println("Enter\n1. To push\n2. To pop\n3. To peek\n4. To display\n5. To exit");
				System.out.println("Enter the choice");
				 int p=in.nextInt();
				switch(p)
				{
					case 1:
						System.out.println("enter the element to be inserted");
						int b=in.nextInt();
						s.push(b);
					break;
					case 2:
						int a=s.pop();
						System.out.println("Popped element is "+a);
					break;
					case 3:
						 l=s.peek();
						System.out.println("The element at the top of stack is "+l);
					break;
					case 4:
						System.out.println("The element in the  stack are: ");
						s.display();
					break;
					case 5:
						break out;
				}//switch ends
			}//while ends
			
		
	}
	
}

/*
OUTPUT:
 
 For static stack
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 1
 enter the element to be inserted
 1
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 1
 enter the element to be inserted
 2
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 1
 enter the element to be inserted
 3
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 1
 enter the element to be inserted
 4
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 2
 Popped element is 4
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 3
 The element at the top of stack is 3
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 4
 The element in the  stack are:
 3
 2
 1
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 5
 For dynamic stack
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 1
 enter the element to be inserted
 10
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 1
 enter the element to be inserted
 20
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 1
 enter the element to be inserted
 30
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 1
 enter the element to be inserted
 40
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 2
 Popped element is 40
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 3
 The element at the top of stack is 30
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 4
 The element in the  stack are:
 30
 20
 10
 Enter
 1. To push
 2. To pop
 3. To peek
 4. To display
 5. To exit
 Enter the choice
 5
*/
