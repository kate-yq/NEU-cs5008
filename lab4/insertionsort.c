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

void insertionSort(int* arr, int len){
    int i, j;
    for (i=1; i<len; i++){
        int temp = arr[i];
        for (j=i; j>=1; j--){
            if (arr[j-1]>temp){
                arr[j] = arr[j-1];
            } else {
                break;
            }
        }
        arr[j] = temp;
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
    insertionSort(arr, len);
    printf("after sort, the array is: \n");
    printArr(arr, len);
    return 0;
}