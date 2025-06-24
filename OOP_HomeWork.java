import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Nguoi {
    private String name;
    private int age;

    Nguoi() {
    }

    Nguoi(String name, int age) {
        this.name = name;
        this.age = age;
    }
    Nguoi(String name) {
        this.name = name; 
    }
    int getAge() {
        return age;
    };

    void setAge(int age) {
        this.age = age;
    };

    String getName() {
        return name;
    };

    void setName(String name) {
        this.name = name;
    };

}

class HocSinh extends Nguoi {
    private String id;
    private double gpa;

    HocSinh(String id, String name, int age, double gpa) {
        super(name, age);
        this.id = id;
        this.gpa = gpa;
    }
    HocSinh(String id ,String name,double gpa) {
        super(name); 
        this.id = id ; 
        this.gpa = gpa; 
    }

    String getId() {
        return id;
    };

    double getGPA() {
        return gpa;
    };

    void setId(String id) {
        this.id = id;
    }

    void setGPa(double gpa) {
        this.gpa = gpa;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return id + " " + getName() + " " + getAge() + " " + gpa;
    }


}

abstract class AbstractManager {
    public abstract void addStudent(HocSinh s);

    public abstract void displayAll();

}

class StudentManager extends AbstractManager {
    private List<HocSinh> list = new ArrayList<>();

    @Override
    public void addStudent(HocSinh s) {
        list.add(s);
    }

    @Override
    public void displayAll() {
        for (HocSinh s : list) {
            System.out.println(s);
        }
    }


public void findById(String id) {
    for (HocSinh s : list) {
        if (s.getId().equals(id)) {
            System.out.println("Find it: " + s);
            return;
        }
    }
    System.out.println("Cant not find student with id: " + id);
}
public void sortGPA() {
    list.sort((a,b) -> Double.compare(b.getGPA() , a.getGPA()));
}
}
class HocSinhHocBong extends HocSinh {
    private double soTien ;
    double getSoTien() {return soTien;}
    void setSoTien(double soTien) {this.soTien = soTien;}

    HocSinhHocBong(String id,String name,double gpa,double soTien) {
        super(id,name, gpa);
        this.soTien = soTien; 
    }
    
public boolean duocHocBong() {
    return getGPA() >= 3.5 ;
}

    @Override
    public String toString() {
        return super.toString() + " | Hoc bong: " + (duocHocBong() ? soTien + " VND" : "Khong");
    }
}



public class OOP_HomeWork {
    public static void main(String[] args) {
        StudentManager sm = new StudentManager();
        Scanner sc = new Scanner(System.in);

        System.out.print("Members Students: ");
        int n = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < n; i++) {
            System.out.println("\n--- Index Student " + (i + 1) + " ---");
            System.out.print("ID: ");
            String id = sc.nextLine();

            System.out.print("Namw: ");
            String name = sc.nextLine();

            System.out.print("AGE: ");
            int age = Integer.parseInt(sc.nextLine());

            System.out.print("GPA: ");
            double gpa = Double.parseDouble(sc.nextLine());

            System.out.print("Student Scholaship ? (y/n): ");
            String type = sc.nextLine();

            if (type.equalsIgnoreCase("y")) {
                System.out.print("Money scholaship: ");
                double soTien = Double.parseDouble(sc.nextLine());
                sm.addStudent(new HocSinhHocBong(id, name, gpa, soTien));
            } else {
                sm.addStudent(new HocSinh(id, name, age, gpa));
            }
        }
        sm.sortGPA();
        System.out.println("\n=== List of student ===");
        sm.displayAll();

        System.out.print("\nID find: ");
        String findId = sc.nextLine();
        sm.findById(findId);

        sc.close();
    }
}
