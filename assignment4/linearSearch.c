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

// helper function
// convert decimal to binary number
int convertToBinary(int d){
    int digit = 1;
    int b = 0;
    while (d>0){
        b = b + digit * (d%2);
        d = d / 2;
        digit = digit * 10;
    }
    return b;
}

// helper function
// convert binary to decimal number
int convertToDecimal(int b){
    int base = 1;
    int d = 0;
    while(b>0){
        d = d + base * (b%10);
        b = b / 10;
        base = base * 2;
    }
    return d;
}

// loop through the array
// and convert every element into binary
void convertToBinaryArr(int* arr, int len){
    int i;
    for (i = 0; i<len; i++){
        arr[i] = convertToBinary(arr[i]);
    }
}

// loop through the array
// and convert every element into binary
void convertToDecimalArr(int* arr, int len){
    int i;
    for (i = 0; i<len; i++){
        arr[i] = convertToDecimal(arr[i]);
    }
}

// search through the array
// return the index if found match
// return -1 if not found
int linearSearch(int* arr, int len, int target){
    int i;
    for (i = 0; i<len; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}


int main(){
    // take inputs

    printf("Input array size: \n");
    int len;
    scanf("%d", &len);
    int arr[len];
    
    printf("Input elements of the array: \n");
    int i;
    for (i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    printf("Input target: \n");
    int target;
    scanf("%d", &target);

    // print the inputs

    printf("The array: \n");
    printArr(arr, len);
    printf("The target: \n%d\n", target);
    
    // convert to binary and print
    
    convertToBinaryArr(arr, len);
    target = convertToBinary(target);
    printf("Converted array: \n");
    printArr(arr, len);
    printf("Converted target: \n%d\n", target);

    // print the search result
    printf("Search result: \n%d\n", linearSearch(arr, len, target));

    // convert to decimal and print
    convertToDecimalArr(arr, len);
    target = convertToDecimal(target);
    printf("Original array: \n");
    printArr(arr, len);
    printf("Original target: \n%d\n", target);
    return 0;
}