import java.lang.annotation.*;
import java.lang.reflect.Field;
import java.util.Scanner;

class Student {
    @Deprecated
    public void loginOld() {
        System.out.println("Phien ban login da cu, vui long dung phien ban khac!");
    }

    public void loginNew() {
        System.out.println("Phien ban dang nhap moi!");
    }
}

// Buoc 1: Tao annotation
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.FIELD)
@interface MinAge {
    int value();
}

// Buoc 2: Tao lop co annotation
class Person {
    @MinAge(25)
    private int age;

    public Person(int age) {
        this.age = age;
    }

    public void display() {
        System.out.println("Age: " + age);
    }

    public int getAge() {
        return age;
    }
}

// Buoc 3: Exception tu dinh nghia
class MyException extends Exception {
    public MyException(String message) {
        super(message);
    }
}

// Buoc 4: Kiem tra logic
class CheckAge {
    public static void checkAge(int age) throws MyException {
        if (age < 0 || age < 18) {
            throw new MyException("Ban chua du tuoi thanh nien (phai tu 18 tro len)");
        }
    }
}

// Buoc 5: Main
public class BaiTap2Annotation {
    public static void main(String[] args) {
        Student st = new Student();
        st.loginOld();  // se bi canh bao @Deprecated
        st.loginNew();

        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap tuoi: ");
        int age = sc.nextInt();
        System.out.println("Tuoi cua ban la: " + age);

        Person person = new Person(age);

        try {
            // 1. Kiem tra bang logic thong thuong
            CheckAge.checkAge(age);

            // 2. Kiem tra bang annotation
            Field field = person.getClass().getDeclaredField("age");
            field.setAccessible(true);
            MinAge minAge = field.getAnnotation(MinAge.class);

            if (minAge != null && person.getAge() < minAge.value()) {
                throw new MyException("Tuoi khong hop le theo @MinAge: " + minAge.value());
            }

            // Neu hop le
            System.out.println("✅ Tuoi hop le.");
            person.display();

        } catch (MyException e) {
            System.out.println("Loi kiem tra tuoi: " + e.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
