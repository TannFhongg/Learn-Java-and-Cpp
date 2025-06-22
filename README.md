Compare POP(Procedure Oriented Programing) vs OOP (Object Oriented Programing) 

-Concept: 
+POP : Chương trình được chia thành các hàm/thủ tục.
+OOP : Chương trình được chia thành các đối tượng.

-Unit: 
+POP : Hàm(Function). 
+OOP : Lớp và đối tượng (Class and Object). 

-Approach:
+POP : Hướng theo quy trình xử lí ( Process Oriented) .
+OOP : Hướng theo quy trình đối tượng ( Process Data).

-Data and Features: 
+POP : Dữ liệu và hàm tách biệt. 
+OOP : Dữ liệu và hàm được đóng gói trong đối tượng. 

Access Modifier / Access Modes

| Từ khóa          | Trong class | Trong package | Class con            | Bên ngoài |
| ---------------- | ----------- | ------------- | -------------------- | --------- |
| `public`         | ✅           | ✅             | ✅                    | ✅         |
| `protected`      | ✅           | ✅             | ✅                    | ❌         |
| *default* (Java) | ✅           | ✅             | ❌ (nếu khác package) | ❌         |
| `private`        | ✅           | ❌             | ❌                    | ❌         |


 Tóm tắt so sánh pass-by-value và pass-by-reference giữa C++ và Java

 | Tiêu chí                      | **Java**                             | **C++**                                       |
| ----------------------------- | ------------------------------------ | --------------------------------------------- |
| Truyền giá trị (value)        | ✔️ Có (`int`, `double`, ...)         | ✔️ Có (`int`, `double`, ...)                  |
| Truyền tham chiếu (reference) | ❌ Không hỗ trợ thật sự               | ✔️ Có (dùng `&` để truyền tham chiếu)         |
| Truyền đối tượng              | ✔️ Truyền bản sao của **tham chiếu** | ✔️ Truyền bản sao hoặc **tham chiếu thực sự** |
| Gán lại đối tượng trong hàm   | ❌ Không ảnh hưởng biến gốc           | ✔️ Có thể thay đổi nếu dùng tham chiếu        |
| Sửa thuộc tính của đối tượng  | ✔️ Được (vì cùng trỏ đến object gốc) | ✔️ Được                                       |

| Loại đa hình     | Đặc điểm                                        |
| ---------------- | ----------------------------------------------- |
| Compile-time     | Nạp chồng hàm/toán tử, quyết định khi biên dịch |
| Run-time         | Dựa vào virtual + con trỏ/tham chiếu lớp cha    |
| Cần `virtual`?   | Có, để đảm bảo runtime gọi đúng hàm ghi đè      |
| Dùng `override`? | Có, để kiểm tra đúng việc ghi đè                |
