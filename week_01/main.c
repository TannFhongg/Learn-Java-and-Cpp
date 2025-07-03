#include <stdio.h>
#include "math.h"   // ✅ đúng cú pháp include

int main() {
    printf("hello world\n");

    int x = add(4, 6);
    printf("add(4, 6) = %d\n", x);

    int y = sub(4, 6);
    printf("sub(4, 6) = %d\n", y);

    return 0;
}
