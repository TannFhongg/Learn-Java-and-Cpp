package com.example;
import java.sql.*;

import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
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
            stmt.setString( 1,"Tuan");
            stmt.setString(2, "tuan@example.com");

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
