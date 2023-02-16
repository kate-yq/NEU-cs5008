#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char val;
    struct node *next;
}nd;

nd *head = NULL;

void push(char element) {
    nd *newNode = (nd*)malloc(sizeof(nd));
    newNode->val= element;
    newNode->next = NULL;

    newNode->next = head;
    head = newNode;
    return;
}

char pop(){
    if (head == NULL){
        return ' ';
    }
    nd* temp = head;
    char ans = temp->val;
    head = head->next;
    free(temp);
    return ans;
}

void deleteStack(){
    while (head != NULL){
        pop();
    }
    free(head);
}

bool isValid(char* s){
    int i = 0;
    while (s[i] != '\0'){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            push(s[i]);
        } else {
            char temp = pop();
            if (temp == ' '){
                return false;
            }
            if (temp == '(' && s[i] != ')'){
                return false;
            }
            if (temp == '[' && s[i] != ']'){
                return false;
            }
            if (temp == '{' && s[i] != '}'){
                return false;
            }
        }
        i++;
    }
    if (pop() == ' '){
        return true;
    }
    return false;
}

int main(){
    char* s = (char*)malloc(128);
    printf("Please input a string contains only (){}[]: \n");
    scanf("%s", s);
    if (isValid(s)){
        printf("This string is valid.\n");
    } else {
        printf("This string is invalid.\n");
    }
    free(s);
    deleteStack();
}