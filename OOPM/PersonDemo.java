/*
 Experiment no.: 14
 Title: Implement multi-level hierarchy of classes
 Name: Kevlyn Kadamala
 Roll No.:8340
 */

class Person
{
    protected int code;
    protected String name;
    Person()
    { }
    Person(String n, int c) //Constructor of superclass
    {
        name=n;
        code=c;
    }
   void display()
    {
        System.out.println("NAME: "+name);
        System.out.println("CODE: "+code);
    }
}
class Faculty extends Person
{
    protected String designation;
    Faculty() 
    { }
    Faculty(String n, int c, String d)
    {
        super(n,c); //call superclass parameterised constructor
        designation=d;
    }
  void display()
    {
        super.display();
        System.out.println("DESIGNATION: "+designation);
    }
}
class SeniorFaculty extends Faculty
{
    private int yearsOfExp;
    SeniorFaculty()
    { }
    SeniorFaculty(String n, int c, String d, int y)
    {
        super(n,c,d); //call superclass parameterised constructor
        yearsOfExp=y;
    }   
    void display()
    {
       super.display();
       System.out.println("YEARS OF EXPERIENCE: "+yearsOfExp);
    }
}
class PersonDemo
{
    public static void main(String args[])
    {
    	SeniorFaculty sf = new SeniorFaculty("PRAMOD SINGH",69854,"Professor",23);
    	Faculty f = new Faculty("HEMANT JAIN",78945,"Assistant Professor");
        Person p = new Person("Dishank Mishra", 8355);
        p.display();
    	f.display();
    	sf.display();
    }
}

/*
 OUTPUT:
 
 NAME: Dishank Mishra
 CODE: 8355
 NAME: HEMANT JAIN
 CODE: 78945
 DESIGNATION: Assistant Professor
 NAME: PRAMOD SINGH
 CODE: 69854
 DESIGNATION: Professor
 YEARS OF EXPERIENCE: 23
 */
