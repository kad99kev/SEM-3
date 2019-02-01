class ThreadN1 implements Runnable
{
    public void run()
    {
      	try 
		{
         		for(int i = 1; i <= 5; i++) 
			{
            			System.out.println("* ");
            			// Let the thread sleep for a while.
            			Thread.sleep(500);//sleep for 500 ms 
         		}
     		}	 
		catch (InterruptedException e) 
		{
         		System.out.println("Child interrupted.");
     		}
     	
		System.out.println("Exiting child thread1.");
   	}
  
}

class ThreadN2 implements Runnable
{
    public void run()
    {
      	try 
		{
         		for(int i = 1; i <= 5; i++) 
			{
            			System.out.println("/ ");
            			// Let the thread sleep for a while.
            			Thread.sleep(1000);//sleep for 500 ms 
         		}
     		}	 
		catch (InterruptedException e) 
		{
         		System.out.println("Child interrupted.");
     		}
     	
		System.out.println("Exiting child thread2.");
   	}
  
}

public class ThreadDemo3
{
    public static void main(String[]args)
    {
        ThreadN1 n1 = new ThreadN1();
        ThreadN2 n2 = new ThreadN2();
        Thread t1 = new Thread(n1,"Demo Thread 1");

      Thread t2 = new Thread(n2,"Demo Thread 2");
      
      System.out.println("Child thread: " + t1);
	 t1.start();

      System.out.println("Child thread: " + t2);
	 t2.start();

     	try{
        t1.join();
        t2.join();
    }
    catch(InterruptedException e){
            e.printStackTrace();
    }
    
      System.out.println("Main thread exiting.");
   }

}