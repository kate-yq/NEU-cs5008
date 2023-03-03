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

void mergeSort(int* arr, int len){
    if (len == 1){
        return;
    }
    int aux1[len/2];
    int aux2[len-len/2];
    int i;
    for (i=0; i<len/2; i++){
        aux1[i] = arr[i];
    }
    for (i = len/2; i<len; i++){
        aux2[i-len/2] = arr[i];
    }
    mergeSort(aux1, len/2);
    mergeSort(aux2, len-len/2);

    // merge
    int a = 0;
    int b = 0;
    i = 0;
    while(a < len/2 && b < len-len/2){
        if (aux1[a] <= aux2[b]){
            arr[i] = aux1[a];
            a++;
        } else {
            arr[i] = aux2[b];
            b++;
        }
        i++;
    }
    while(a < len/2){
        arr[i] = aux1[a];
        a++;
        i++;
    }
    while(b < len-len/2){
        arr[i] = aux2[b];
        b++;
        i++;
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
    mergeSort(arr, len);
    printf("after sort, the array is: \n");
    printArr(arr, len);
    return 0;
}