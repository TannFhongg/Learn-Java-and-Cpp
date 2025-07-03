| Thuộc tính       | **Stack**                         | **Heap**                             | **static** 
| ---------------- | --------------------------------- | ------------------------------------ |---------------------------
| Quản lý          | Tự động (LIFO – vào sau ra trước) | Thủ công (do lập trình viên quản lý) |tồn tại suốt vòng đời chương 
| Cấp phát bộ nhớ  | Khi khai báo biến cục bộ          | Dùng `malloc`, `calloc`, `new`       |trình 
| Giải phóng       | Tự động khi thoát khối/hàm        | Phải `free()` hoặc `delete`          |
| Kích thước       | Giới hạn (thường < 1–8 MB)        | Lớn (tùy RAM hệ thống)               |
| Tốc độ           | Rất nhanh                         | Chậm hơn do quản lý động             |
| Vị trí trong RAM | Do hệ điều hành quản lý           | Do OS cấp phát từ vùng heap          |
| Lỗi phổ biến     | Stack overflow                    | Memory leak, dangling pointer        |
'

 1. Stack allocation (biến cục bộ):
// cấp phát bộ nhớ tạm thời,lưu trữ các biến bên trong hàm,được quản lí bởi CPU 


void func() {
    int a = 10;        // Cấp phát trên stack
    int arr[100];      // Mảng cũng nằm trên stack
}
📌 Biến a và arr sẽ tự động bị giải phóng khi hàm func() kết thúc.

2. Heap allocation (bằng malloc):
#include <stdlib.h>

void func() {
    int* p = (int*) malloc(sizeof(int));  // Cấp phát trên heap
    *p = 42;

    free(p);  // 🔥 QUAN TRỌNG: giải phóng để tránh memory leak
}
📌 Biến p nằm trên stack, nhưng vùng nhớ malloc cấp phát nằm trên heap