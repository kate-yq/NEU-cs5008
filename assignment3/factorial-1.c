/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void factorial(int num){
    
    int fact = 1;
    int i;
    for(i = 1;i<=num;++i){
        fact = fact * i;
    }
    
    printf("The factorial of %d is %d \n",num,fact);
    
}

int main() {
    
    int factNumber = 6;
    factorial(factNumber);

    return 0;
}