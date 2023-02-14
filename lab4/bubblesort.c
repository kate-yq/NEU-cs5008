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

void bubbleSort(int* arr, int len){
    bool sorted;
    int i, j;
    for (i=0; i<len; i++){
        sorted = true;
        for (j=0; j<len-1; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted = false;
            }
        }
        if (sorted){
            break;
        }
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
    bubbleSort(arr, len);
    printf("after sort, the array is: \n");
    printArr(arr, len);
    return 0;
}