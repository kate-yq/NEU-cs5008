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

void swap(int* arr, int aIndex, int bIndex){
    int temp = arr[aIndex];
    arr[aIndex] = arr[bIndex];
    arr[bIndex] = temp;
}

void quickSort(int* arr, int left, int right){
    if (left >= right){
        return;
    }
    int front = left;
    int end = right;
    while (front < end){
        if (arr[front + 1] < arr[front]){
            swap(arr, front, front+1);
            front++;
        } else if (arr[front + 1] == arr[front]){
            front++;
        } else {
            swap(arr, front+1, end);
            end--;
        }
    }
    quickSort(arr, left, front-1);
    quickSort(arr, front+1, right);
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
    quickSort(arr, 0, len-1);
    printf("after sort, the array is: \n");
    printArr(arr, len);
    return 0;
}