/*
 Experiment no.: 10
 Title: Write a program to count no. of letters, digits, spaces and special characters in a string
 Name: Kevlyn Kadamala
 Roll No.: 8340
 */

import java.util.Scanner;

public class VowCon
{
    public static void main(String[]args)
    {
        int l=0, d=0, sp=0, sc=0, i=0;
        String s=new String();
        Scanner input=new Scanner(System.in);
        System.out.println("Enter string");
        s=input.nextLine();
        char []a= new char[s.length()];
        a=s.toCharArray();
        for(i=0; i<s.length(); i++)
        {
            if(Character.isLetter(a[i]))
                l++;
            else
            {
                if(Character.isDigit(a[i]))
                    d++;
                else
                {
                    if(Character.isWhitespace(a[i]))
                        sp++;
                    else
                        sc++;
                }
            }
        }
        System.out.println("The number of\nLetters are "+l+"\nDigits are "+d+"\nSpaces are "+sp+"\nSpecial Characters are "+sc);
    }
}
/*
 OUTPUT:
 
 Enter string
 H3ll0 W*rld
 The number of
 Letters are 7
 Digits are 2
 Spaces are 1
 Special Characters are 1
 */
