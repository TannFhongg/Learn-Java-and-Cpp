typedef là 1 từ khóa dùng trong C để đặt tên mới cho 1 kiểu dữ kiệu có sẵn 

=> nó không tạo ra kiểu dữ liệu mới chỉ là tên gọi khác dễ nhớ hơn 

Cú pháp tổng quát : typedef existing_name new_name 

vd: typedef usigned int unit; 
unit age = 25; tương đương với usinged int age = 25; 

Thường được dùng cho struct, pointer, function pointer,usigned int; 



Example : 


#include <stdio.h>

#define int_pointer int * 

int_pointer chalk,chesee; // same int *chalk,chesse; 

#typedef char* char_pointer 

char_pointer benly,Rolls_Roys; //same char *benly,Rolls_Roys; 

Trong C, typedef hay #define thay thế tên kiểu theo từng biến, chứ không mở rộng ra toàn bộ danh sách khai báo.