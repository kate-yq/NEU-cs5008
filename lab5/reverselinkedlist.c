#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *next;
}Node;

Node* head = NULL;

// build linked list
void add(int element) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = element;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *itr = head;
    while (itr->next != NULL) {
        itr = itr->next;
    }
    itr->next = newNode;
}

// print
void print(Node* n){
    Node* itr = n;
    while(itr != NULL){
        printf("%d ", itr->val);
        itr = itr->next;
    }
    printf("\n");
}

// free memory
void delete(){
    while (head != NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    free(head);
}


// major function reverse linked list
Node* reverse(Node* head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node* new_head = reverse(head->next);
    Node* new_tail = head->next;
    new_tail->next = head;
    head->next = NULL;
    return new_head;
}

int main(){
    int len;
    printf("How long the linked lisk you want to  create\n");
    scanf("%d", &len);
    int i;
    for (i=1; i<=len; i++){
        int val;
        printf("Input the %d th value: \n", i);
        scanf("%d", &val);
        add(val);
    }
    
    printf("the original linked list is: \n");
    print(head);
    printf("the reversed linked list is: \n");
    Node* reversedHead = reverse(head);
    print(reversedHead);

    delete();
    return 0;
}