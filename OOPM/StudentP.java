package p1;
import java.util.Scanner;
public class StudentP
{
    int rollno,n;
    String name;
    public StudentP()
    {}
    public StudentP(int r, String n)
    {
        rollno = r;
        name = n;
    }
    
    public String toString()
    {
        return "["+rollno+","+name+"]";
    }
}
