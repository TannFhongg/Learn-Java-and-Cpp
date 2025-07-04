#include <stdio.h> 
#include <malloc.h> 

struct  myArray
{
    /* data */

    int arraySize; 
    int array[];
    
};

int main() {
    int n; 
    printf("So luong phan tu trong mang la : ");
    scanf("%d",&n); 

    

    struct myArray *ptr = malloc(sizeof(struct myArray) + n * sizeof(int)); 

    if(ptr = NULL) {
        printf("Khong the cap phat bo nho"); 
        return 1; 
    }

    ptr->arraySize = n; 
    for(int i = 0; i < n ; i++) {
        printf("Phan tu thu %d: ", i); 
        scanf("%d", &ptr->array[i]); 
    }
    printf("list of elemnet array flexible: "); 
    for (int i = 0; i < n ; i ++) { 
        printf("%d ", ptr-> array[i]); 
    }

    free(ptr); 
    return 0; 
}