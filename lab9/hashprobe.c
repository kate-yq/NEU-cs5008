#include <stdlib.h>
#include <stdio.h>

void singleProbe(int element, int* arr, int size){
    int key = element % size;
    int attempt = 1;
    while (arr[key] != -1){
        key = (key+1) % size;
        attempt++;
        if(attempt > size+1){
            printf("no empty space");
            return;
        }
    }
    arr[key] = element;
}

void quadraticProbe(int element, int* arr, int size){
    int key = element % size;
    int attempt = 1;
    while(arr[key] != -1){
        key = (key + attempt*attempt) % size;
        attempt++;
        if (attempt > size*2){
            printf("no empty space or fill in infinite loop");
            return;
        }
    }
    arr[key] = element;
}

void doubleHash(int element, int* arr, int size){
    int h1 = element % size;
    int h2 = 7 - (element % 7);
    int key = (h1 + h2) % size;
    int attempt = 1;
    while(arr[key] != -1){
        key = (h1 + attempt*h2) % size;
        attempt++;
        if (attempt > size*2){
            printf("no empty space or fill in infinite loop");
            return;
        }
    }
    arr[key] = element;
}

int main(){
    int choice;
    printf("1-Single Probing; 2-Quadratic Probing; 3-Double Hashing\n");
    scanf("%d", &choice);
    if (choice < 1 || choice > 3){
        printf("invalid choice\n");
        return 0;
    }

    int size;
    int k;
    printf("Map size: \n");
    scanf("%d", &size);
    printf("Number of values: \n");
    scanf("%d", &k);

    int hashmap[size];

    int i;
    for (i = 0; i<size; i++){
        hashmap[i] = -1;
    }


    for (i=0; i<k; i++){
        int num;
        printf("Input %d th value: \n", i+1);
        scanf("%d", &num);
        switch(choice){
            case 1:
                singleProbe(num, hashmap, size);
                break;
            case 2:
                quadraticProbe(num, hashmap, size);
                break;
            case 3:
                doubleHash(num, hashmap, size);
                break;
        }
    }

    for (i=0; i<size; i++){
        if (hashmap[i] != -1){
            printf("%d ", hashmap[i]);
        } else {
            printf("NULL ");
        }
    }
    printf("\n");

    return 0;
}