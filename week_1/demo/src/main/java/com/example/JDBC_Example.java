package com.example;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Scanner;

class XuLiNgoaiLe extends Exception {
    public XuLiNgoaiLe(String message) {
        super(message);
    }
}

class KiemTraNgoaiLe {
    private static String regex = "^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$";

    static void invalid(String name, String email) throws XuLiNgoaiLe {
        if (name == null || name.trim().isEmpty()) {
            throw new XuLiNgoaiLe("Tên không được để trống!");
        }
        if (email == null || !email.matches(regex)) {
            throw new XuLiNgoaiLe("Email không hợp lệ!");
        }
    }
}

public class JDBC_Example {
    public static void main(String[] args) {

        String url = "jdbc:postgresql://localhost:5432/testdatabase";
        String username = "postgres";
        String password = "@Luvbaetula1";

        try (
            Scanner sc = new Scanner(System.in);
            Connection conn = DriverManager.getConnection(url, username, password);
            PreparedStatement stmt = conn.prepareStatement("INSERT INTO users(name,email) VALUES(?,?)")
        ) {
            System.out.print("Nhập số thành viên cần thêm vào: ");
            int n = sc.nextInt();
            sc.nextLine();
            System.out.println("Kết nối thành công tới database!");

            for (int i = 0; i < n; i++) {
                System.out.println("\n--- Thành viên thứ " + (i + 1) + " ---");

                System.out.print("Nhập tên: ");
                String name = sc.nextLine();

                System.out.print("Nhập email: ");
                String email = sc.nextLine();

                try {
                    KiemTraNgoaiLe.invalid(name, email);
                    stmt.setString(1, name);
                    stmt.setString(2, email);

                    int rows = stmt.executeUpdate();
                    if (rows > 0) {
                        System.out.println("Đã thêm " + name + " - " + email);
                    }
                } catch (XuLiNgoaiLe e) {
                    System.out.println("Lỗi dữ liệu: " + e.getMessage());
                    i--; // cho người dùng nhập lại
                }
            }

        } catch (SQLException e) {
            System.out.println("Lỗi kết nối hoặc truy vấn database:");
            e.printStackTrace();
        }
    }
}
