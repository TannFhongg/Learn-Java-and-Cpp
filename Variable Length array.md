Variable Length Array 

là mảng có kích thước được xác định tại thời điểm chạy (run time) chứu không phải thời điểm biên dịch(compile time) 

Khác với mảng thông thường,VLA cho phép khai báo kích thước của mảng phụ thuộc vào BIẾN 

=> không dùng mảng này như BIẾN TOÀN CỤC (Global) hoặc với static 

cú pháp khai báo : 

void example(int n) {
    int arr[n]; // đây là variable length array 
}

Bộ nhớ được cấp phát trên Stack 

So sánh Mảng tĩnh vầ mảng động 

| Tiêu chí            | Mảng tĩnh (`int a[10]`) | VLA (`int a[n]`) | Cấp phát động (`malloc`) |
| ------------------- | ----------------------- | ---------------- | ------------------------ |
| Kích thước xác định | ✅ Biên dịch             | ✅ Khi chạy       | ✅ Khi chạy               |
| Bộ nhớ              | Stack                   | Stack            | Heap                     |
| Tự động giải phóng  | ✅ Có                    | ✅ Có             | ❌ Phải `free()`          |
| Dùng ngoài hàm      | ✅ Có                    | ❌ Không          | ✅ Có                     |

