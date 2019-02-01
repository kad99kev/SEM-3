/*
 Experiment no.: 3
 Title:accept strings using command line arguments and then printing it alphabetically
 Name: Kevlyn Kadamala
 Roll No.:8340
 */

import java.util.Scanner;

public class CLSort
{
    public static void main(String[]args)
    {
        if(args.length == 0)
        {
            System.out.println("Cannot proceed");
            System.exit(0);
        }
        else
        {
            String temp=new String();
            for(int i=0; i<args.length;  i++)
            {
                for(int j=0; j<args.length-1; j++)
                {
                    if(args[j].compareTo(args[j+1])>=0)
                    {
                        temp=args[j];
                        args[j]=args[j+1];
                        args[j+1]=temp;
                    }
                }
            }
            System.out.println("Sorted Students are");
            for(int i=0; i<args.length;  i++)
            {
                System.out.println(args[i]);
            }
        }
        
    }
}
/*
 OUTPUT:
 
 java CLSort
 Cannot proceed
 
 java CLSort Sherwyn Mohit Kevlyn Abhishek
 Sorted Students are
 Abhishek
 Kevlyn
 Mohit
 Sherwyn
*/
