/*
Experiment no.: 17
Title: Write a program that demonstrates dynamic method dispatch.
Name: Kevlyn Kadamala
Roll No.: 8340
*/

import java.util.*;

abstract class Shape
{
	
	abstract String getName();
	
	abstract double getArea();
	
	abstract double getPerimeter();

	public String toString()
	{
		return (getName()+"\nArea="+getArea()+"\nPerimeter=" +getPerimeter());
	}
}
class Circle extends Shape
{
	private double radius;
	
	Circle()
	{}
	
	Circle(double r)
	{
		radius = r;
	}
	
	double getArea()
	{
		return Math.PI * (radius * radius);
	}
	
	double getPerimeter()
	{
		return 2*Math.PI*radius;
	} 	
	
	String getName()
	{
		return "Circle";
	}
}
class Rectangle extends Shape 
{
	private double length;
	private double width;
	
	Rectangle()
	{}

	Rectangle(double length, double width)
	{
		this.length = length;
		this.width = width;
	}
	double getArea()
	{
		return length * width;
	}

	double getPerimeter()
	{
		return 2*(length+width);
	}
      	String getName()
	{
		return "Rectangle";
	}
}
class Square extends Rectangle	
{	
	Square()
	{}

	Square(double length)
	{
		super(length, length);
	}
	String getName()
	{
		return "Square";
	}
}
class Triangle extends Shape
{
	private double side1,side2,side3;
	
	Triangle()
	{}

	Triangle(double side1, double side2,double side3)
	{
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
		
	}
	double getArea()
	{	double p= this.getPerimeter();
		return Math.sqrt(p*(p-side1)*(p-side2)*(p-side3));
	}

	double getPerimeter()
	{
		return (side1+side2+side3)/2;
	}
        String getName()
	{
		return "Triangle";
	}
}
class Etriangle extends Triangle
{
	Etriangle()
	{}
	
	Etriangle(double side)
	{
		super(side,side,side);
	}
	String getName()
	{
		return "Equilateral Triangle";
	}

}

public class abstractShape
{
	public static void main(String[] args) 
	{
		Shape[] a = new Shape[5];

		a[0] = new Circle(2.5);
		a[1] = new Rectangle(2,5);
		a[2] = new Square(3);
		a[3] = new Triangle(2,3,4);
		a[4] = new Etriangle(3);
 
		for(int i = 0; i < a.length; i++)
			System.out.println(a[i]);
	}
}
/*
OUTPUT:
 
 Circle
 Area=19.634954084936208
 Perimeter=15.707963267948966
 Rectangle
 Area=10.0
 Perimeter=14.0
 Square
 Area=9.0
 Perimeter=12.0
 Triangle
 Area=2.9047375096555625
 Perimeter=4.5
 Equilateral Triangle
 Area=3.897114317029974
 Perimeter=4.5
*/
