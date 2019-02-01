/*
 Experiment no.: 7
 Title:Write a Program to add two complex numbers passing Object as a parameter to function.
 Name: Kevlyn Kadamala
 Roll No.: 8340
 */

import java.util.Scanner;

class Complex
{
    int real,img;
    
    
    Complex()
    {}
    
    Complex(int x,int y)
    {
        real=x;
        img=y;
    }
    
    void add(Complex p1,Complex p2)
    {
        real=p1.real + p2.real;
        img=p1.img + p2.img;
    }
    
    void mul(Complex p1,Complex p2)
    {
        real=(p1.real*p2.real)-(p1.img*p2.img);
        img=(p1.real*p2.img)+(p1.img*p2.real);
    }
    
    void display()
    {
        System.out.println(real+ "+" + "(" +img+ ")" + "i");
    }
    
}

public class complexMain
{
    public static void main(String[]args)
    {
        Complex c1=new Complex(2,3);
        Complex c2=new Complex(4,5);
        Complex c3=new Complex();
        Complex c4=new Complex();
        c3.add(c1,c2);
        System.out.println("After addition");
        c3.display();
        c4.mul(c1,c2);
        System.out.println("After multiplication");
        c4.display();
    }
}
/*
 OUTPUT:
 
 After addition
 6+(8)i
 After multiplication
 -7+(22)i
 */

