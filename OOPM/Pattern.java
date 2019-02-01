/*
 Experiment no.: 1
 Title: Display star pattern
 Name: Kevlyn Kadamala
 Roll No.:8340
 */

import java.util.Scanner;

public class Pattern
{
    public static void main(String[]args)
    {
        int i, j, n;
        Scanner row=new Scanner(System.in);
        System.out.println("Enter number of rows");
        n=row.nextInt();
        int s=n-1;
    out: for(i=1; i<=n; i++)
        {
            System.out.println();
            for(j=1; j<=s; j++)
                System.out.print(" ");
            s--;
            for(j=1; j<=n; j++)
            {
                if(j==i+1)
                    continue out;
                System.out.print("* ");
            }
        }
        System.out.println();
    }
}

/* Enter number of rows
 Enter number of rows
 4
 
    *
   * *
  * * *
 * * * *
 
 */
