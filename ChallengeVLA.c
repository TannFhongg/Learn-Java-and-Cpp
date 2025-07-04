#include <stdio.h> 


void sumArr(int arr[],int n) {
    int sum =0; 
    for(int i =0 ; i < n;i++) {
        sum +=arr[i]; 
    }
    printf("sum: %d",sum); 
}
int main() {
int n;

printf("nhap so luong phan tu cua mang VLA: "); 
scanf("%d",&n); 
int arr[n]; 
for(int i =0; i < n; i++) {
    printf("Nhap phan tu thu %d: ",i); \
    scanf("%d",&arr[i]); 
}

sumArr(arr,n); 

return 0;
}