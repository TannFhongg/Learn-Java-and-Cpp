/* 
import java.util.Scanner;

class CheckAge { 
   public static void checkAge(int age) throws ArithmeticException { 
        if(age < 18) { 
            throw new ArithmeticException("Age is not valid");
        }
    }
}

class BankAccount {
    private double balance;
    public BankAccount(double balance) {
        this.balance = balance;
    }
    public void withdraw(int amount) throws LowBalanceException {
        if(amount > balance) {
            throw new LowBalanceException("Insufficient balance");
        }
        balance -= amount;
        System.out.println("Withdraw successful");
    }
}
class LowBalanceException extends Exception {
    public LowBalanceException(String message) {
        super(message);
    }
}
class BaiTapException { 
    Scanner sc = new Scanner(System.in);
    public void main(String[] args) {
        try {
            System.out.println("Enter your age: ");
            int age = sc.nextInt();
            CheckAge.checkAge(age);
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
        }
        BankAccount account = new BankAccount(1000);
        try {
            System.out.println("Enter the amount to withdraw: ");
            int amount = sc.nextInt();
            account.withdraw(amount);
        } catch (LowBalanceException e) {
            System.out.println(e.getMessage());
        }
    }
}

*/