#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CAPACITY = 10;
int existing = 0;

typedef struct node {
    int data;
    int priority;
    struct node *next;
}nd;

nd* head = NULL;


bool isEmpty(){
    return head == NULL;
}


bool isFull(){
    return existing == CAPACITY;
}


void enqueue(int data, int priority) {
    if (isFull()){
        printf("the priority queue is full.\n");
        return;
    }

    nd *newNode = (nd*)malloc(sizeof(nd));
    newNode->data= data;
    newNode->priority =priority;

    existing++;

    if (head == NULL){
        head = newNode;
        return;
    }

    if (head->priority >= priority){
        newNode->next = head;
        head = newNode;
        return;
    }

    nd* itr = head;
    while(itr->next != NULL && itr->next->priority < priority){
        itr = itr->next;
    }
    
    newNode->next = itr->next;
    itr->next = newNode;
}


int dequeue() {
    if(isEmpty()){
        printf("the priority queue is empty.\n");
        return -1;
    }
    existing--;

    int ans = head->data;
    nd* temp = head;
    head = head->next;
    free(temp);
    return ans;
}


// print
void printPQ(){
    nd* itr = head;
    while(itr != NULL){
        printf("%d -> ", itr->data);
        itr = itr->next;
    }
    printf("NULL\n");
}


// free memory
void deleteLinkedList(){
    while (head != NULL){
        nd* temp = head;
        head = head->next;
        free(temp);
    }
    free(head);
}


int main(){

    printf("1.Enqueue  2.Dequeue  3.isEmpty  4.isFull  5.exit\n");
    int ans;
    scanf("%d", &ans);
    while(ans != 5){
        switch(ans){
            case 1:
                printf("input the data: \n");
                int data;
                scanf("%d", &data);
                printf("input the priority: \n");
                int priority;
                scanf("%d", &priority);
                enqueue(data, priority);
                break;
            case 2:
                printf("the top priority data is: %d\n", dequeue());
                break;
            case 3:
                if (isEmpty()){
                    printf("it is empty.\n");
                } else {
                    printf("it is not empty.\n");
                }
                break;
            case 4:
                if (isFull()){
                    printf("it is full.\n");
                } else {
                    printf("it is not full.\n");
                }
                break;
            default:
                printf("illegal chioce.\n");
        }
        printf("now the PQ is: ");
        printPQ();
        printf("1.Enqueue  2.Dequeue  3.isEmpty  4.isFull  5.exit\n");
        scanf("%d", &ans);
    }

    deleteLinkedList();
    return 0;
}