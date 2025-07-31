#include <stdio.h>

typedef int(*ptr_int_to_func)(void) ; 


int say_Hello() {
    printf("Hello !\n") ; 

    return 13; 

}

typedef int (*operation_t)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

void execute(operation_t op, int x, int y) {
    printf("Result: %d\n", op(x, y));
}

int main() {

    char *p = (char*) &say_Hello;

    ptr_int_to_func f = (ptr_int_to_func) p ; 
    int res = f(); 

    printf("%d",res); 

    execute(add,10,5); 
    
}