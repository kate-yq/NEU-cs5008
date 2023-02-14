#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printArr(int* arr, int len){
    int i;
    for (i=0; i<len; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int* arr, int len){
    int i, j;
    for (i=0; i<len-1; i++){
        int minindex = i;
        for (j=i+1; j<len; j++){
            if (arr[j]<arr[minindex]){
                minindex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}

int main(){
    printf("How large this arr you want it to be?\n");
    int len;
    scanf("%d", &len);
    int arr[len];
    int i;
    for (i=0; i<len; i++){
        printf("Input the number at index %d: \n", i);
        scanf("%d", &arr[i]);
    }

    printf("your original array is: \n");
    printArr(arr, len);
    selectionSort(arr, len);
    printf("after sort, the array is: \n");
    printArr(arr, len);
    return 0;
}