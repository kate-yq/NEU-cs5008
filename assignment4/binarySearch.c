#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printArr(int* arr, int len){
    int i;
    for (i=0; i<len; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// sort the nums array together with their indices
void insertionSort(int* arr, int* indice, int len){
    int i, j;
    for (i=1; i<len; i++){
        int temp = arr[i];
        int tempIndex = indice[i];
        for (j=i; j>=1; j--){
            if (arr[j-1]>temp){
                arr[j] = arr[j-1];
                indice[j] = indice[j-1];
            } else {
                break;
            }
        }
        arr[j] = temp;
        indice[j] = tempIndex;
    }
}

// binary search the array
// return the index if found match
// return -1 if not found
int binarySearch(int* arr, int* indice, int len, int target){
    // sort input first
    insertionSort(arr, indice, len);

    // then binary search for the target
    int left = 0;
    int right = len-1;
    while (left <= right){
        int mid = (left + right)/2;
        if (arr[mid] < target){
            left = mid+1;
        } else if (arr[mid] > target){
            right = mid-1;
        } else {
            // return the corresponding index
            return indice[mid];
        }
    }

    // not found: return -1
    return -1;
}

int main(){
    // take inputs

    printf("Input array size: \n");
    int len;
    scanf("%d", &len);
    int arr[len];
    int indice[len];
    
    printf("Input elements of the array: \n");
    int i;
    for (i=0; i<len; i++){
        scanf("%d", &arr[i]);
        indice[i] = i;
    }

    printf("Input target: \n");
    int target;
    scanf("%d", &target);

    // print the inputs

    printf("The array: \n");
    printArr(arr, len);
    printf("The target: \n%d\n", target);
    
    // print search result
    printf("Search result: \n%d\n", binarySearch(arr, indice, len, target));

    return 0;
}