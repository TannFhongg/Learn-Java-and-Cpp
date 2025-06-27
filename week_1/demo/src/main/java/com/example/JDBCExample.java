package com.example;
import java.sql.*;
import java.util.Scanner;



public class JDBCExample {   
    public static void main(String[] args) {
        // 1. Cấu hình kết nối
        String url = "jdbc:postgresql://localhost:5432/testdb";
        String username = "postgres";
        String password = "@Luvbaetula1";
        
        try {
            // 2. Kết nối CSDL
            Connection conn = DriverManager.getConnection(url, username, password);
            System.out.println("Kết nối thành công!");

            // 3. Thực thi câu lệnh
            String sql = "INSERT INTO users(name, email) VALUES (?, ?)";
            PreparedStatement stmt = conn.prepareStatement(sql);
            Scanner scanner = new Scanner(System.in);
            System.out.println("Nhập tên: ");
            String name = scanner.nextLine();
            
            System.out.println("Nhập email: ");
            String email = scanner.nextLine();

            stmt.setString( 1,name);
            stmt.setString(2, email);
            scanner.close();
            int rows = stmt.executeUpdate();
            if (rows > 0) {
                System.out.println("Thêm thành công!");
            }

            // 4. Đóng kết nối
            stmt.close();
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
