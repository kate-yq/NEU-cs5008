#include <stdlib.h>
#include <stdio.h>

// helper function: sink
void sink(int* heap, int cur, int size){
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
            sink(heap, left, size);
        }
    } else {
        if (heap[right]>heap[cur]){
            int temp = heap[cur];
            heap[cur] = heap[right];
            heap[right] = temp;
            sink(heap, right, size);
        }
    }
    return;
}


// helper function: swimup
void siwmup(int* heap, int cur){
    if (cur == 0){
        return;
    }
    int parent = (cur-1)/2;
    if (heap[cur] > heap[parent]){
        int temp = heap[cur];
        heap[cur] = heap[parent];
        heap[parent] = temp;
        swimup(heap, parent);
    }
    return;
}

// build
void buildMaxHeap(int* arr, int size){
    int i;
    for (i=size/2; i>=0; i--){
        sink(arr, i, size);
    }
}

// insertion
// insert at the end
// siwm up

void addElement(int* heap, int size, int target, int capacity){
    if (size == capacity){
        printf("cannot add new element, heap is full");
        return;
    }
    heap[size] = target;
    siwmup(heap, size);
}

// deletion - pop
// exchange top with end
// remove the end 
// sink the top
int pop_max(int* heap, int size){
    int temp = heap[0];
    heap[0] = heap[size-1];
    heap[size-1] = 0;
    sink(heap, 0, size-1);
    return temp;
}



int main(){
    return 0;
}

