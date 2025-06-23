// Interface Person
interface Person {
    String getName();

    String getAddress();

    void setName(String name);

    void setAddress(String address);

    void in(); 
}


interface GPAInfo {
    void setGPA(double gpa);

    double getGPA();
}

// Class Student implements 2 interface
class Student implements Person, GPAInfo {
    private String name;
    private String address;
    private double gpa;

    // Constructors
    Student() {
    }

    Student(String name, String address, double gpa) {
        this.name = name;
        this.address = address;
        this.gpa = gpa;
    }

    // Implement methods from Person
    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    // Implement methods from GPAInfo
    public void setGPA(double gpa) {
        this.gpa = gpa;
    }

    public double getGPA() {
        return gpa;
    }

    // Display method
    @Override
    public void in() {
        System.out.println(name + " " + address);
        System.out.printf("GPA: %.2f\n", gpa);
    }
}

public class OOP_Interface {
    public static void main(String[] args) {
   

        Person p = new Student("Tuanvv", "DongHoi", 3.0);

        p.in();
    }
}
