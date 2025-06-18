import java.util.Scanner;

class SinhVien {
    private String id, name, birthday;
    private double gpa;
    String maSv;

@Override
public String toString() {
    return maSv + " " + id +" " + name + " " + birthday + " " + gpa; 
}

    static int dem; 
    public SinhVien() {
        maSv = String.format("SV%03d",++dem); // "%03d" = 3 chữ số, thêm số 0 ở đầu nếu thiếu
    }

    public SinhVien(String id, String name, String birthday, double gpa) {
        this.id = id;
        this.name = name;
        this.birthday = birthday;
        this.gpa = gpa;
    }

    public double getGPA() {
        return gpa;
    }

    public void nhap() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Nhap id: ");
        id = sc.nextLine();
        System.out.print("Nhap name: ");
        name = sc.nextLine();
        System.out.print("Nhap ngay sinh: ");
        birthday = sc.nextLine();
        System.out.print("Nhap GPA: ");
        gpa = sc.nextDouble();
        sc.nextLine(); // Clear buffer
    }

    // public void in() {
    //     System.out.println(maSv+ " " + id + " " + name + " " + birthday + " " + gpa);
    // }

    // public static boolean Compare(SinhVien a, SinhVien b) {
    //     return a.getGPA() > b.getGPA();
    // }
}



public class OOP_Encapsulation {
    public static void main(String[] args) {
     
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so sinh vien: ");
        n = sc.nextInt();
        sc.nextLine(); // clear buffer

        SinhVien[] a = new SinhVien[100];

        for (int i = 0; i < n; i++) {
            a[i] = new SinhVien();
            a[i].nhap();
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].getGPA() < a[j].getGPA()) {
                    SinhVien temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        System.out.println("\nDanh sach sinh vien:");
        for (int i = 0; i < n; i++) {
            System.out.println(a[i]);
        }
    }
}
