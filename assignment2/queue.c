#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    // 0 is head, 9 is end
    int ary[10];
    int size;
}queue;

// constructor
queue* makeQueue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->size = 0;
    return q;
}

void enqueue(queue* q, int element){
    if (q->size == 10){
        printf("cannot enqueue\n");
        return;
    }
    q->ary[q->size] = element;
    (q->size)++;
}

void dequeue(queue* q){
    if (q->size == 0){
        printf("cannot dequeue\n");
        return;
    }
    for (int i=0; i < q->size -1; i++){
        q->ary[i] = q->ary[i+1];
    }
    q->ary[q->size-1] = 0;
    (q->size)--;
}

bool isEmpty(queue* q){
    return (q->size) == 0;
}

bool isFull(queue* q){
    return (q->size) == 10;
}

int peek(queue* q){
    if (q->size == 0){
        printf("cannot peek\n");
        return 0;
    }
    return q->ary[0];
}

void deleteQueue(queue* q){
    free(q);
}

int main(){
    queue* q = makeQueue();
    if (isEmpty(q)){
        printf("this queue is empty now.\n");
    }
    for (int i=0; i<10; i++){
        enqueue(q, i);
    }
    if (isFull(q)){
        printf("this queue is full now.\n");
    }
    printf("the top is: %d\n", peek(q));
    dequeue(q);
    printf("the top is: %d\n", peek(q));
    dequeue(q);
    deleteQueue(q);
    return 0;
}

