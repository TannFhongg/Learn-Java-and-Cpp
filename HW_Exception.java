// Java chia thành:

// Checked Exception (bi?t tr??c, b?t bu?c ph?i x? lý)

// Unchecked Exception (runtime exception, không b?t bu?c x? lý)
/* 

| Lo?i      | K? th?a t?         | B?t bu?c x? lý | Ví d?                                     |
| --------- | ------------------ | -------------- | ----------------------------------------- |
| Checked   | `Exception`        | ?              | IOException, SQLException                 |
| Unchecked | `RuntimeException` | ?              | NullPointerException, ArithmeticException |

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
     * throw: dùng ?? ném ra ngo?i l?.
     * 
     * throws: dùng trong khai báo ph??ng th?c, cho bi?t có th? ném ngo?i l? nào.
     */

    static void invalid(String name,int age) throws MyException {
        if(name == null || name.trim().isEmpty()) {
            throw new MyException("Name is empty");
        }
        if (age < 0 || age < 18) {
            throw new MyException("You are not an adult");
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
