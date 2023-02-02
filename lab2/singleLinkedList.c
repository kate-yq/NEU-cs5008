#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
}nd;

nd *head = NULL;

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
void insertMiddle(int element, int position) {
    nd *newNode = (nd*)malloc(sizeof(nd));
    newNode->val= element;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

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
    itr->next = newNode;
}

void insertHead(int element) {
    insertMiddle(element, 0);
}

void insertEnd(int element) {
    nd *newNode = (nd*)malloc(sizeof(nd));
    newNode->val = element;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    nd *itr = head;
    while (itr->next != NULL) {
        itr = itr->next;
    }
    itr->next = newNode;
}

// delete node
void deleteHead() {
    if (head == NULL){
        return;
    }
    nd* temp = head;
    head = head->next;
    free(temp);
    return;
}

void deleteMiddle(int tgt) {
    if (head == NULL){
        return;
    }
    if (head->val == tgt){
        deleteHead();
        return;
    }
    nd* itr = head;
    while(itr->next != NULL){
        if (itr->next->val == tgt){
            nd* temp = itr->next;
            itr->next = temp->next;
            free(temp);
            return;
        }
        itr = itr->next;
    }
    return;
}

void deleteEnd(){
    nd *temp = head;
    nd *prev = NULL;
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// print
void print(){
    nd* itr = head;
    while(itr != NULL){
        printf("%d ", itr->val);
        itr = itr->next;
    }
    printf("\n");
}

// free memory
void deleteLinkedList(){
    while (head != NULL){
        deleteHead();
    }
    free(head);
}

int main(){
    insertHead(3);
    insertHead(8);
    insertEnd(5);
    insertMiddle(2, 2);
    print();
    printf("Found 2 at position %d. \n", search(2));
    printf("Found 7 at position %d. \n", search(7));
    deleteHead();
    deleteEnd();
    print();
    deleteMiddle(7);
    deleteMiddle(3);
    print();
    deleteLinkedList();
    return 0;
}