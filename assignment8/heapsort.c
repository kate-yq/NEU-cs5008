#include <stdlib.h>
#include <stdio.h>

// helper function: print array
void printArr(int* arr, int len){
    int i;
    for (i=0; i<len; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

// helper function: sink
void sinkMaxHeap(int* heap, int cur, int size){
    if (size == 1){
        return;
    }
    int left = cur*2+1;
    int right = cur*2+2;
    if(left >= size){
        return;
    }
    if (right >= size){
        if (heap[left]>heap[cur]){
            int temp = heap[cur];
            heap[cur] = heap[left];
            heap[left] = temp;
        }
        return;
    }
    if (heap[left] > heap[right]){
        if (heap[left]>heap[cur]){
            int temp = heap[cur];
            heap[cur] = heap[left];
            heap[left] = temp;
            sinkMaxHeap(heap, left, size);
        }
    } else {
        if (heap[right]>heap[cur]){
            int temp = heap[cur];
            heap[cur] = heap[right];
            heap[right] = temp;
            sinkMaxHeap(heap, right, size);
        }
    }
    return;
}

// build
void buildMaxHeap(int* arr, int size){
    int i;
    for (i=size/2; i>=0; i--){
        sinkMaxHeap(arr, i, size);
    }
}

// deletion - pop
// exchange top with end
// remove the end 
// sink the top
int pop_max(int* heap, int size){
    if (size == 1){
        return heap[0];
    }
    int temp = heap[0];
    heap[0] = heap[size-1];
    heap[size-1] = 0;
    sinkMaxHeap(heap, 0, size-1);
    return temp;
}


// helper function: sink
void sinkMinHeap(int* heap, int cur, int size){
    if (size == 1){
        return;
    }
    int left = cur*2+1;
    int right = cur*2+2;
    if(left >= size){
        return;
    }
    if (right >= size){
        if (heap[left]<heap[cur]){
            int temp = heap[cur];
            heap[cur] = heap[left];
            heap[left] = temp;
        }
        return;
    }
    if (heap[left] < heap[right]){
        if (heap[left]<heap[cur]){
            int temp = heap[cur];
            heap[cur] = heap[left];
            heap[left] = temp;
            sinkMinHeap(heap, left, size);
        }
    } else {
        if (heap[right]<heap[cur]){
            int temp = heap[cur];
            heap[cur] = heap[right];
            heap[right] = temp;
            sinkMinHeap(heap, right, size);
        }
    }
    return;
}

// build
void buildMinHeap(int* arr, int size){
    int i;
    for (i=size/2; i>=0; i--){
        sinkMinHeap(arr, i, size);
    }
}

// deletion - pop
// exchange top with end
// remove the end 
// sink the top
int pop_min(int* heap, int size){
    int temp = heap[0];
    heap[0] = heap[size-1];
    heap[size-1] = 0;
    sinkMinHeap(heap, 0, size-1);
    return temp;
}

int main(){
    printf("How large this arr you want it to be?\n");
    int len;
    scanf("%d", &len);
    int arr1[len];
    int arr2[len];
    int i;
    for (i=0; i<len; i++){
        int temp;
        printf("Input the number at index %d: \n", i+1);
        scanf("%d", &temp);
        arr1[i] = temp;
        arr2[i] = temp;
    }

    printf("Your original array is: \n");
    printArr(arr1, len);

    int ascending[len];
    int descending[len];

    buildMinHeap(arr1, len);
    buildMaxHeap(arr2, len);

    for (i=0; i<len; i++){
        ascending[i] = pop_min(arr1, len-i);
        descending[i] = pop_max(arr2, len-i);
    }

    printf("Ascending order: \n");
    printArr(ascending, len);
    printf("Ascending order: \n");
    printArr(descending, len);
}