import java.util.*;

class Person {
    private String name, address;

    Person() {
    }

    Person(String name, String address) {
        this.name = name;
        this.address = address;
    }

    String getName() {
        return name;
    }

    String getAddress() {
        return address;
    }

    void setName(String name) {
        this.name = name;
    }

    void setAddress(String address) {
        this.address = address;
    }

    void in() {
        System.out.println(name + " " + address + " ");
    }
}

class Student extends Person {
    private double gpa;

    void setGPA(double gpa) {
        this.gpa = gpa;
    }

    double getGPA() {
        return gpa;
    }

    @Override
    void in() {
        super.in();
        System.out.println(gpa + " ");
    }

    Student(String name, String address, double gpa) {
        super(name, address);
        this.gpa = gpa;
    }

    Student() {
    }
}


// // Interface Person
// interface Person {
//     String getName();
//     String getAddress();
//     void setName(String name);
//     void setAddress(String address);
//     void in(); // in thông tin
// }

// // Interface GPAInfo (tạo thêm để mô phỏng đa kế thừa)
// interface GPAInfo {
//     void setGPA(double gpa);
//     double getGPA();
// }

// // Class Student implements 2 interface
// class Student implements Person, GPAInfo {
//     private String name;
//     private String address;
//     private double gpa;

//     // Constructors
//     Student() {}

//     Student(String name, String address, double gpa) {
//         this.name = name;
//         this.address = address;
//         this.gpa = gpa;
//     }

//     // Implement methods from Person
//     public String getName() {
//         return name;
//     }

//     public String getAddress() {
//         return address;
//     }

//     public void setName(String name) {
//         this.name = name;
//     }

//     public void setAddress(String address) {
//         this.address = address;
//     }

//     // Implement methods from GPAInfo
//     public void setGPA(double gpa) {
//         this.gpa = gpa;
//     }

//     public double getGPA() {
//         return gpa;
//     }

//     // Display method
//     public void in() {
//         System.out.println(name + " " + address);
//         System.out.printf("GPA: %.2f\n", gpa);
//     }
// }
public class OOP_Inheritance {
    public static void main(String args[]) {

        Student s = new Student();

        s.setName("Tuanvv");
        s.setAddress("QuangBinh");
        s.setGPA(3.0);
        s.in();

        Student ss = new Student("Datvv", "Dong Hoi", 3.6);
        ss.in();
    }
}
