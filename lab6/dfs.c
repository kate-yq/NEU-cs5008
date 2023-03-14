#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

// the followings are dfs functions
// print each val when visited

void preorder(node* cur){

    printf("%d ", cur->val);

    if (cur->left != NULL){
        preorder(cur->left);
    }

    if (cur->right != NULL){
        preorder(cur->right);
    }
}

void inorder(node* cur){

    if (cur->left != NULL){
        inorder(cur->left);
    }

    printf("%d ", cur->val);

    if (cur->right != NULL){
        inorder(cur->right);
    }
}

void postorder(node* cur){

    if (cur->left != NULL){
        postorder(cur->left);
    }

    if (cur->right != NULL){
        postorder(cur->right);
    }

    printf("%d ", cur->val);
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

    printf("Preorder: \n");
    preorder(n1);
    printf("\n");

    printf("Inorder: \n");
    inorder(n1);
    printf("\n");
    
    printf("Postorder: \n");
    postorder(n1);
    printf("\n");

    delete(n1);
    return 0;
}