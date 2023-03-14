#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}node;

node* makeNode(int val, node* left, node* right){
    node* cur = (node*)malloc(sizeof(node));
    cur->val = val;
    cur->left = left;
    cur->right = right;
    return cur;
}

void delete(node* root){
    if (root != NULL){
        delete(root->left);
        delete(root->right);
    }
    free(root);
}

// the followings are the implement of Queue
// contains only the necessary methods

typedef struct queue {
    // 0 is head, 99 is end
    node* ary[100];
    int size;
}queue;

void enqueue(queue* q, node* element){
    q->ary[q->size] = element;
    (q->size)++;
}

node* dequeue(queue* q){
    node* temp = q->ary[0];
    for (int i=0; i < q->size -1; i++){
        q->ary[i] = q->ary[i+1];
    }
    q->ary[q->size-1] = 0;
    (q->size)--;
    return temp;
}

bool isEmpty(queue* q){
    return (q->size) == 0;
}

// the followings are bfs function
// print each val when visited

void bfs(node* root){
    queue* helper = (queue*)malloc(sizeof(queue));
    helper->size = 0;

    enqueue(helper, root);

    while(!isEmpty(helper)){
        node* cur = dequeue(helper);
        printf("%d ", cur->val);
        if (cur->left != NULL){
            enqueue(helper, cur->left);
        }
        if (cur->right != NULL){
            enqueue(helper, cur->right);
        }
    }

    printf("\n");
    free(helper);
}

int main(){

    // construct the binary tree

    node* leaf8 = makeNode(8, NULL, NULL);
    node* leaf9 = makeNode(9, NULL, NULL);
    node* leaf10 = makeNode(10, NULL, NULL);
    node* leaf11 = makeNode(11, NULL, NULL);
    node* leaf12 = makeNode(12, NULL, NULL);
    node* leaf13 = makeNode(13, NULL, NULL);
    node* leaf14 = makeNode(14, NULL, NULL);
    node* leaf15 = makeNode(15, NULL, NULL);
    node* n4 = makeNode(4, leaf8, leaf9);
    node* n5 = makeNode(5, leaf10, leaf11);
    node* n6 = makeNode(6, leaf12, leaf13);
    node* n7 = makeNode(7, leaf14, leaf15);
    node* n2 = makeNode(2, n4, n5);
    node* n3 = makeNode(3, n6, n7);
    node* n1 = makeNode(1, n2, n3);

    bfs(n1);

    delete(n1);
    return 0;
}