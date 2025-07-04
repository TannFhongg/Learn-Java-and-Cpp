#include <stdlib.h> 
#include <stdio.h> 
struct  Student
{
    /* data */
    int id; 
    char name[20]; 
    float score;

};

int main() {
    struct Student s = { 
        .id = 1, 
        .name = "tuanvv", 
        .score =10
    }; 
int arr[6] = { [4] =10, [5]= 11} ; 
printf("%d - %s - %.2f\n",s.id , s.name , s.score); 

for (int i = 0; i < 6; i++)
{
    /* code */
    printf("%d ",arr[i]); 
}


    return 0; 
}
