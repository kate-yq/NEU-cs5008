#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
}nd;

nd *head = NULL;
nd *tail = NULL;

// search node
int search(int tgt){
    int count = 0;
    nd* itr = head;
    while(itr != NULL){
        if (itr->val == tgt){
            return count;
        }
        itr = itr->next;
        count++;
    }
    return -1;
}

// insert node
void insertHead(int element) {
    if (head == NULL){
        head = (nd*)malloc(sizeof(nd));
        head->val = element;
        tail = head;
        return;
    }
    nd *newNode = (nd*)malloc(sizeof(nd));
    newNode->val= element;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertMiddle(int element, int position) {
    if (position == 0) {
        insertHead(element);
        return;
    }

    nd *newNode = (nd*)malloc(sizeof(nd));
    newNode->val= element;
    newNode->prev = NULL;
    newNode->next = NULL;

    nd *itr = head;
    int curPosition = 0;
    while (itr != NULL && curPosition < position - 1) {
        itr = itr->next;
        curPosition++;
    }
    if (itr == NULL) {
        printf("the position is larger than the size of Linked List\n");
        return;
    }
    newNode->next = itr->next;
    newNode->prev = itr;
    newNode->next->prev = newNode;
    itr->next = newNode;
}

void insertEnd(int element) {
    if (tail == NULL){
        tail = (nd*)malloc(sizeof(nd));
        tail->val = element;
        head = tail;
        return;
    }
    nd *newNode = (nd*)malloc(sizeof(nd));
    newNode->val= element;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

// delete node
void deleteHead() {
    if (head == NULL){
        return;
    }
    nd* temp = head;
    head = head->next;
    free(temp);
    head->prev = NULL;
    return;
}

void deleteEnd(){
    if (tail == NULL){
        return;
    }
    tail = tail->prev;
    free(tail->next);
    tail->next = NULL;
    return;
}

void deleteMiddle(int tgt) {
    if (head->val == tgt) {
        deleteHead();
        return;
    }
    if (tail->val == tgt) {
        deleteEnd();
        return;
    }

    nd* itr = head;
    while(itr != NULL){
        if (itr->val == tgt){
            nd* temp = itr;
            itr->next->prev = itr->prev;
            itr->prev->next = itr->next;
            free(temp);
            return;
        }
        itr = itr->next;
    }
    return;
}

// print
void printReverse(){
    nd* itr = tail;
    while(itr != NULL){
        printf("%d ", itr->val);
        itr = itr->prev;
    }
    printf("\n");
}

// free memory
void deleteLinkedList(){
    if (head == NULL){
        return;
    }
    while (head->next != NULL){
        deleteEnd();
    }
    free(head);
}

int main(){
    insertHead(3);
    insertHead(8);
    insertEnd(5);
    insertMiddle(2, 2);
    printReverse();
    printf("Found 2 at position %d. \n", search(2));
    printf("Found 7 at position %d. \n", search(7));
    deleteHead();
    deleteEnd();
    printReverse();
    deleteMiddle(7);
    deleteMiddle(3);
    printReverse();
    deleteLinkedList();
    return 0;
}