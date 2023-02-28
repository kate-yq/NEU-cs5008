#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int fact(int n){
    if (n <= 1){
        return 1;
    }
    return n * fact(n-1);
}

int main(){
    int n;
    printf("Input the number: \n");
    scanf("%d", &n);
    printf("the %d factorial is %d. \n", n, fact(n));

    return 0;
}