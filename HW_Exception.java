
// Java chia thành:

// Checked Exception (biết trước, bắt buộc phải xử lý)

// Unchecked Exception (runtime exception, không bắt buộc xử lý)
/* 

| Loại      | Kế thừa từ         | Bắt buộc xử lý | Ví dụ                                     |
| --------- | ------------------ | -------------- | ----------------------------------------- |
| Checked   | `Exception`        | ✅              | IOException, SQLException                 |
| Unchecked | `RuntimeException` | ❌              | NullPointerException, ArithmeticException |

 */

import java.io.EOFException;
import java.util.Scanner;

class MyException extends Exception {
    public MyException(String message) {
        super(message);
    }
}

public class HW_Exception {

    /*
     * throw vs throws
     * throw: dùng để ném ra ngoại lệ.
     * 
     * throws: dùng trong khai báo phương thức, cho biết có thể ném ngoại lệ nào.
     */

    static void invalid(String name,int age) throws MyException {
        if (age < 0 || age < 18) {
            throw new MyException("You are not an adult");
        }
        if(name == null || name.trim().isEmpty()) {
            throw new MyException("Name is empty");
        }
    }
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your name: ");
        String name = sc.nextLine();
        System.out.println("Enter your age: ");
        int age = sc.nextInt();
        try {
            invalid(name, age); 
        } catch (MyException e) {
            System.out.println(e.getMessage());
        }
        sc.close();
    }
}
