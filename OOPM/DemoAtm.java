import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
class Atm1 
 {
       
    Scanner kbd = new Scanner(System.in);
    String password="secomps";	
	public void pass1(String z) throws IOException
    {

        String  pass, origBal = "error",new1;
        int count = 0, menuOption = 0,g;
        boolean  foundNonDigit;               
        do
        {
            foundNonDigit = false;
            
            pass=z;
            origBal = checkID(pass);

            count++;

            if (count >= 3 && origBal.equals("error"))
            {
                System.out.println(" YOU HAVE REACHED THE MAXIMUM ATTEMPTS ");
                System.exit(0);
            }
            
            
        }while(origBal.equals("error"));
        MenuWindow mu=new MenuWindow();
        mu.MenuGraphics();
    }		
    public  String checkID( String pwd) throws IOException// checks whether the given password is correct or not 
    {
        String result = "error";
        if (pwd.equals(password))
            return result = "correct";

        return result;
    }
}
class DemoAtm 
{
   
    public static void main(String[] args) throws IOException
    {

        Scanner kbd1 = new Scanner(System.in);
        Atm1 atm=new Atm1();
        String new2;
        int menuOption = 0,g;
        LoginWindow lw=new LoginWindow();
		lw.LoginGraphics(); 
        
    }
}
class LoginWindow implements ActionListener //opens a window to enter and get the password checked
{
	public void LoginGraphics()
	{
		new LoginWindow();
	}
	JFrame f;
	JLabel welcome;//WrongPassword;
	JTextField  password;
	JButton Signin;
	
	LoginWindow()
	{
		welcome = new JLabel("Enter your password : ");
		password = new JTextField(9);
		Signin = new JButton(" Sign in ");
		//WrongPassword = new jLabel("Sorry wrong password, re-enter your password");
		f = new JFrame("ATM");
		f.setSize(500,400);
		f.setLayout(new FlowLayout());
		f.setVisible(true);
		f.add(welcome);
		f.add(password);
		f.add(Signin);
		Signin.addActionListener(this);
	}
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource()==Signin)
		{
			try
			{
				String a = password.getText();
				Atm1 atm = new Atm1();
				atm.pass1(a);
			}catch(IOException e)
			{
				System.out.println(e);
			}	
		}	
	}
}

class MenuWindow implements ActionListener//opens menuwindow
{
	public void MenuGraphics()
	{
		new MenuWindow();
	}
	JFrame f;
	JLabel Menu;
	JButton deposit,withdraw,statement,changepassword,exit;
	
	MenuWindow()
	{
		Menu = new JLabel("You are in ! Now PLease Exit It:-");
		
		exit = new JButton("Exit");
		f = new JFrame("Menu");
		f.setSize(300,300);
		f.setLayout(new FlowLayout());
		f.setVisible(true);
		f.add(Menu);
		f.add(exit);
		exit.addActionListener(this);
	}	
		public void actionPerformed(ActionEvent ae) 
		{	
			if(ae.getSource()==exit)
			{
				System.exit(0);
			}	
		}
}    