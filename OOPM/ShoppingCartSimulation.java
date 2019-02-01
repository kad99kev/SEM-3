
/*
Experiment no.: 12
Title: Shopping Cart Simulation
Name: Kevlyn Kadamala
Roll No.: 8340
*/

import java.util.*;

class ProductItem
{
	private int id;
	private double price;
	ProductItem(int id,double price)
	{
		this.id=id;
		this.price=price;
	}
	double getPrice()
	{
		return price; //private members are accessed using non-private method
	}
	public String toString()
	{
		return "ID : "+(id)+" Price : "+price; //string representation of Product Item
	}
}
class ShoppingCart
{
	int custid;
	Vector itemsv;

	ShoppingCart(int custid)
	{
		this.custid=custid;
		itemsv=new Vector();
	}
	public void addItem(ProductItem item)
	{
		itemsv.add(item);
	}
	public void removeItem(ProductItem item)
	{
		itemsv.remove(item);
	}
	public void showAllItem()
	{
		for(int i=0;i<itemsv.size();i++)
		{
			ProductItem temp=(ProductItem)itemsv.get(i);
			System.out.println(temp);
		}
	}
	public double calculateAmt()
	{
		double amt=0.0;
		for(int i=0;i<itemsv.size();i++)
		{
			ProductItem temp=(ProductItem)itemsv.get(i);
			amt=amt+temp.getPrice();
		}
		return amt;
	}



}
public class ShoppingCartSimulation
{
	public static void main(String[] args)
	{
		
		ProductItem [] p = new ProductItem[11];//there are total 10 items , p[1] is first item

		populateItems(p);
		
		ShoppingCart [] sc=new ShoppingCart[6]; //5 shopping carts

		Scanner in = new Scanner(System.in);
		
		for(int i=1;i<3;i++)  //can create n no. of shopping lists.
		{	sc[i] = new ShoppingCart(i);
			System.out.println("Enter the details for shopping cart "+i+":");
		out:	do
			{
				System.out.println("1.Add item \n2. Remove item \n3. Make final Payment");
				System.out.print("Enter your option: ");
				int option = in.nextInt();
				switch(option)
				{
					case 1:
						System.out.println("Which item put in bag:= ");
						int item_no1 = in.nextInt();
	
						sc[i].addItem(p[item_no1]);
	
					break;
					case 2:
						System.out.println("Which item to remove from bag:= ");
						int item_no2 = in.nextInt();
	
						sc[i].removeItem(p[item_no2]);
					break;
					case 3:
						System.out.println("Printed Bill");
						sc[i].showAllItem();
						System.out.println("You have to make payment of "+sc[i].calculateAmt()+" in shopping list "+i);
						
						break out; //leave the shop
				}	
			}while(true);		
		}	
	}

static void populateItems(ProductItem [] h)
	{
		Scanner in = new Scanner(System.in);
		for(int i = 1; i < h.length; i++)
		{
			System.out.println("Enter price of a product item "+i+":= ");
			double price = in.nextDouble();
			h[i] = new ProductItem(i,price);
		}
	}
}
/*
OUTPUT:
 
 Enter price of a product item 1:=
 10
 Enter price of a product item 2:=
 25
 Enter price of a product item 3:=
 30
 Enter price of a product item 4:=
 40
 Enter price of a product item 5:=
 50
 Enter price of a product item 6:=
 60
 Enter price of a product item 7:=
 75
 Enter price of a product item 8:=
 80
 Enter price of a product item 9:=
 99
 Enter price of a product item 10:=
 150
 Enter the details for shopping cart 1:
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 2
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 4
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 6
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 2
 Which item to remove from bag:=
 4
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 10
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 3
 Printed Bill
 ID : 2 Price : 25.0
 ID : 6 Price : 60.0
 ID : 10 Price : 150.0
 You have to make payment of 235.0 in shopping list 1
 Enter the details for shopping cart 2:
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 1
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 3
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 5
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 7
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 9
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 2
 Which item to remove from bag:=
 5
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 2
 Which item to remove from bag:=
 1
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 3
 Printed Bill
 ID : 3 Price : 30.0
 ID : 7 Price : 75.0
 ID : 9 Price : 99.0
 You have to make payment of 204.0 in shopping list 2
 Enter price of a product item 1:=
 10
 Enter price of a product item 2:=
 25
 Enter price of a product item 3:=
 30
 Enter price of a product item 4:=
 40
 Enter price of a product item 5:=
 50
 Enter price of a product item 6:=
 60
 Enter price of a product item 7:=
 75
 Enter price of a product item 8:=
 80
 Enter price of a product item 9:=
 99
 Enter price of a product item 10:=
 150
 Enter the details for shopping cart 1:
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 2
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 4
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 6
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 2
 Which item to remove from bag:=
 4
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 10
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 3
 Printed Bill
 ID : 2 Price : 25.0
 ID : 6 Price : 60.0
 ID : 10 Price : 150.0
 You have to make payment of 235.0 in shopping list 1
 Enter the details for shopping cart 2:
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 1
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 3
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 5
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 7
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 1
 Which item put in bag:=
 9
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 2
 Which item to remove from bag:=
 5
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 2
 Which item to remove from bag:=
 1
 1.Add item
 2. Remove item
 3. Make final Payment
 Enter your option: 3
 Printed Bill
 ID : 3 Price : 30.0
 ID : 7 Price : 75.0
 ID : 9 Price : 99.0
 You have to make payment of 204.0 in shopping list 2
*/
