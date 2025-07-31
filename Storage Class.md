| Storage Class | Mục đích chính                            | Nơi khai báo         | Thời gian tồn tại    | Vị trí lưu trữ       | Phạm vi sử dụng (Scope) |
| ------------- | ----------------------------------------- | -------------------- | -------------------- | -------------------- | ----------------------- |
| `auto`        | Biến cục bộ mặc định                      | Trong hàm (default)  | Trong block          | Stack                | Block nội bộ            |
| `register`    | Biến cần truy xuất nhanh (ưu tiên CPU)    | Trong hàm            | Trong block          | Thanh ghi (nếu được) | Block nội bộ            |
| `static`      | Biến cục bộ có vòng đời toàn chương trình | Trong hoặc ngoài hàm | Toàn bộ chương trình | Static memory        | Block nội bộ / toàn cục |
| `extern`      | Sử dụng biến được định nghĩa ở nơi khác   | File khác / đầu file | Toàn bộ chương trình | Static memory        | Toàn cục (Global)       |


✅ 1. auto (biến tự động)
Khai báo: auto int x = 5; → nhưng thường viết đơn giản: int x = 5;

Vị trí: Trong hàm

Phạm vi: Chỉ dùng trong block

Tồn tại: Từ khi vào block đến khi thoát block

Khởi tạo tự động: ❌ Không, chứa rác nếu không gán giá trị


void func() {
    int x = 10; // auto
}

✅ 2. register (ưu tiên lưu trên thanh ghi CPU)
Khai báo: register int count = 0;

Mục đích: Biến truy cập thường xuyên (VD: biến đếm)

Không lấy được địa chỉ (&) của biến register

Compiler có thể bỏ qua đề nghị nếu không có thanh ghi phù hợp

void func() {
    register int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
}


✅ 3. static (biến tĩnh)
Có 2 loại:

🟠 a. Static local variable (Biến tĩnh cục bộ)
Giữ giá trị giữa các lần gọi hàm

Không bị mất khi thoát khỏi hàm


void counter() {
    static int count = 0; // chỉ khởi tạo 1 lần
    count++;
    printf("count = %d\n", count);
}
🟢 b. Static global variable
Dùng khi muốn giới hạn phạm vi biến toàn cục trong file hiện tại

Không thể truy cập từ file khác (file-scope private)

static int maxUsers = 100; // global nhưng chỉ dùng trong file này


✅ 4. extern (biến khai báo từ file khác)
Dùng để khai báo biến toàn cục được định nghĩa ở nơi khác

Không cấp phát bộ nhớ, chỉ tham chiếu

// File A.c
int value = 10;

// File B.c
extern int value;
printf("%d", value); // dùng được biến từ file A.c
💡 Dùng nhiều trong chương trình nhiều file (modular C).

| Thuộc tính                            | `auto`             | `register`             | `static`                   | `extern`                 |
| ------------------------------------- | ------------------ | ---------------------- | -------------------------- | ------------------------ |
| **Từ khóa**                           | `auto` (mặc định)  | `register`             | `static`                   | `extern`                 |
| **Scope (Phạm vi)**                   | Cục bộ (block)     | Cục bộ (block)         | Cục bộ hoặc toàn cục       | Toàn cục (global)        |
| **Lifetime (Tồn tại)**                | Trong block        | Trong block            | Trong suốt chương trình    | Trong suốt chương trình  |
| **Khởi tạo mặc định**                 | ❌ Không            | ❌ Không                | ✅ Nếu global: 0            | ❌ Không                  |
| **Giữ giá trị giữa các lần gọi hàm?** | ❌ Không            | ❌ Không                | ✅ Có                       | ✅ Có                     |
| **Được cấp phát bộ nhớ?**             | ✅ Có               | ✅ Có (nếu đủ register) | ✅ Có                       | ❌ Không (chỉ khai báo)   |
| **Địa chỉ (`&`) lấy được?**           | ✅ Có               | ❌ Không                | ✅ Có                       | ✅ Có (nếu đã định nghĩa) |
| **Dùng để?**                          | Biến tạm, ngắn hạn | Biến truy xuất nhanh   | Biến tĩnh hoặc nội bộ file | Dùng biến từ file khác   |


