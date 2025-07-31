#include <stdio.h>
#include "Example.h"

extern int ShareValue; 

void increase(); 
int main () { 
increase(); 
increase(); 

printf("%d",ShareValue); 
}