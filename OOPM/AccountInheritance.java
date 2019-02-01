/*
Experiment no.: 15
Title: Implement hierarchical inheritance for the classes Savings Account and Current Account 
 Name: Kevlyn Kadamala
 Roll No.: 8340
 */

import java.util.*;
class BankAccount
{
	protected double balance;
	protected int accno;

	private static int last;

	BankAccount()
	{
		accno = ++last;
		balance = 500.0;//mandatory to open with min balance
	}

	BankAccount(double balance)
	{
		accno = ++last;
		this.balance = balance;
	}
	
	void withdraw(double amt)
	{
		if(balance >= amt)
		{
			balance-=amt; //subtract amt from balance
		}
		else
		{
			System.out.println("No sufficient balance");
		}

	}
	void deposit(double amt)
	{
		balance +=amt;
	}
	public String toString()
	{
		return("Current Balance = "+balance);
	}
}

class SavingsAccount extends BankAccount
{
	private double interest_rate;
	private double x; //interest deposited
	
	SavingsAccount()
	{
		interest_rate = 10;	
	}

	SavingsAccount(double rate)
	{
		interest_rate = rate;
	}

	void addInterest()
	{
		 x = balance*(interest_rate/100);
		deposit(x);
	}
	public String toString()
	{
		return(super.toString()+" and the entry made "+x );
	}
}

class CheckingAccount extends BankAccount
{
	int transactionCount;
	private static final int FREE_TRA = 3;
	private static final double TRA_FEE = 2.0;
	private double rate;
	 void withdraw(double amt)
	{
		transactionCount++;
        deductFees();
		super.withdraw(amt); //call inherited method

	}

	 void deposit(double amt)
	{
		transactionCount++;
        deductFees();
		super.deposit(amt);
	}
		
	public void deductFees()
	{
		if(transactionCount > FREE_TRA)
		{
			rate = TRA_FEE *(transactionCount-FREE_TRA);
			transactionCount = 0;
			super.withdraw(rate);
		}
	}
	public String toString()
	{
		return(super.toString()+" and the entry deducted "+rate );
	}
	
}
 public class AccountInheritance
{
	public static void main(String [] args)
	{	
		double n;
		int b,i=1,j=1;
		Scanner in = new Scanner(System.in);
		CheckingAccount a = new CheckingAccount();
		SavingsAccount d = new SavingsAccount();
			System.out.println("Enter the type of the account :1.Savings 2.Checking");
			int q=in.nextInt();
			switch(q)
			{
                case 1:
                {
                    while(i!=0)
                    {
                        System.out.println("Enter the operation to be performed:\n1. Checking balance\n2. Deposit\n3. Withdrawal");
                        b = in.nextInt();
                        switch(b)
                        {
                            case 1:
                            {
                                d.addInterest();
                                System.out.println("Account balance:\n"+d);
                            }
                                break;
                            case 2:
                            {
                                System.out.println("Enter amount to be deposited:");
                                n = in.nextDouble();
                                a.deposit(n);
                                System.out.println(a);
                            }
                                break;
                            case 3:
                            {
                                System.out.println("Enter amount to be withdrawn:");
                                n = in.nextDouble();
                                a.withdraw(n);
                                System.out.println(a);
                            }
                                break;
                            default:
                            {
                                System.out.println("ERROR 404");
                            }
                        }
                        System.out.println("Enter any number to continue or 0->To exit");
                        i=in.nextInt();
                    }
                    break;
                }
                	
		        case 2:
                {
                    while(i!=0)
                    {
                        System.out.println("Enter the operation to be performed:\n1. Checking balance\n2. Deposit\n3. Withdrawal");
                        b = in.nextInt();
                              switch(b)
                              {
                                  case 1:
                                  {
                                      a.deductFees();
                                      System.out.println("Account balance:\n"+a);
                                      break;
                                  }
                                  case 2:
                                  {
                                      System.out.println("Enter amount to be deposited:");
                                      n = in.nextDouble();
                                      a.deposit(n);
                                      System.out.println(a);
                                  }
                                      break;
                                  case 3:
                                  {
                                      System.out.println("Enter amount to be withdrawn:");
                                      n = in.nextDouble();
                                      a.withdraw(n);
                                      System.out.println(a);
                                  }
                                      break;
                                  default:
                                  {
                                      System.out.println("ERROR 404");
                                  }
                              }
                              System.out.println("Enter any number to continue or 0->To exit");
                              i=in.nextInt();
                          }
                     break;
                }
            }
    }
}

/*
 OUTPUT:
 
 Enter the type of the account :1.Savings 2.Checking
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 1
 Account balance:
 Current Balance = 550.0 and the entry made 50.0
 Enter any number to continue or 0->To exit
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 2
 Enter amount to be deposited:
 500
 Current Balance = 1000.0 and the entry deducted 0.0
 Enter any number to continue or 0->To exit
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 3
 Enter amount to be withdrawn:
 250
 Current Balance = 750.0 and the entry deducted 0.0
 Enter any number to continue or 0->To exit
 0
 
 Enter the type of the account :1.Savings 2.Checking
 2
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 1
 Account balance:
 Current Balance = 500.0 and the entry deducted 0.0
 Enter any number to continue or 0->To exit
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 2
 Enter amount to be deposited:
 500
 Current Balance = 1000.0 and the entry deducted 0.0
 Enter any number to continue or 0->To exit
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 3
 Enter amount to be withdrawn:
 500
 Current Balance = 500.0 and the entry deducted 0.0
 Enter any number to continue or 0->To exit
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 2
 Enter amount to be deposited:
 1000
 Current Balance = 1500.0 and the entry deducted 0.0
 Enter any number to continue or 0->To exit
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 1
 Account balance:
 Current Balance = 1500.0 and the entry deducted 0.0
 Enter any number to continue or 0->To exit
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 3
 Enter amount to be withdrawn:
 1250
 Current Balance = 248.0 and the entry deducted 2.0
 Enter any number to continue or 0->To exit
 1
 Enter the operation to be performed:
 1. Checking balance
 2. Deposit
 3. Withdrawal
 1
 Account balance:
 Current Balance = 248.0 and the entry deducted 2.0
 Enter any number to continue or 0->To exit
 0
 */
