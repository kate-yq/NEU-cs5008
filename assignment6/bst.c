#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
}node;

void addNewNum(int val, node* root){
    struct node* cur = (node*)malloc(sizeof(node));
    cur->val = val;
    if (root == NULL){
        root = cur;
        return;
    }
    node* itr = root;
    
    while(itr != NULL){
        if (val < itr->val){
            if (itr->left == NULL){
                itr->left = cur;
                break;
            } else {
                itr = itr->left;
            }
        } else if (val > itr->val){
            if (itr->right == NULL){
                itr->right = cur;
                break;
            } else {
                itr = itr->right;
            }
        } else {
            return;
        }
    }
}

int find(float target, node* root){
    if (root == NULL){
        return -1;
    }
    int prev = root->val;
    int cur;
    node* itr = root;

    while(itr != NULL){
        cur = itr->val;
        if (target < cur){
            if (itr->left == NULL){
                if (fabsf(prev - target) < fabsf(cur - target)){
                    return prev;
                } else {
                    return cur;
                }
            } else {
                itr = itr->left;
                prev = cur;
            }
        } else if (target > cur){
            if (itr->right == NULL){
                if (fabsf(prev - target) < fabsf(cur - target)){
                    return prev;
                } else {
                    return cur;
                }
            } else {
                itr = itr->right;
                prev = cur;
            }
        } else {
            return cur;
        }
    }
    return cur;
}

void delete(node* root){
    if (root == NULL){
        free(root);
        return;
    }
    delete(root->left);
    delete(root->right);
    free(root);
}

int main(){
    struct node* root = (node*)malloc(sizeof(node));

    printf("Do u want to add number to the BST?(Y/N)\n");
    char ans;
    scanf("%s", &ans);
    while(ans == 'Y' || ans == 'y'){
        printf("input number: \n");
        int val;
        scanf("%d", &val);
        addNewNum(val, root);
        printf("Do u want to add number to the BST?(Y/N)\n");
        scanf("%s", &ans);
    }

    printf("Input the number you want to find \n");
    float target;
    scanf("%f", &target);

    printf("closest number = %d\n", find(target, root));

    delete(root);

    return 0;
}