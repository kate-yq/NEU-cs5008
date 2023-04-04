#include <stdlib.h>
#include <stdio.h>

typedef struct mapnode{
    int val;
    struct mapnode* next;
}node;

void printHashMap(node** hashmap, int size){
    int i;
    for (i = 0; i<size; i++){
        printf("Chain[%d] -> ", i);
        node* itr = hashmap[i];
        while(itr != NULL){
            printf("%d -> ", itr->val);
            itr = itr->next;
        }
        printf("NULL\n");
    }
}

void add(int element, node** hashmap, int size){
    node* item = (node*)malloc(sizeof(node));
    item->val = element;
    int key = element % size;
    if (hashmap[key] == NULL){
        hashmap[key] = item;
        return;
    }
    node* itr = hashmap[key];
    while(itr->next!=NULL){
        if (itr->next->val == element){
            free(item);
            return;
        }
        itr = itr->next;
    }
    itr->next = item;
}


void deleteChain(node* root){
    if (root == NULL){
        return;
    }
    deleteChain(root->next);
    free(root);
}

void deleteHashMap(node** hashmap, int size){
    int i;
    for(i=0; i<size; i++){
        deleteChain(hashmap[i]);
    }
    free(hashmap);
}


int main(){
    int size;
    int k;
    printf("Chain size: \n");
    scanf("%d", &size);
    printf("Number of values: \n");
    scanf("%d", &k);

    node** hashmap = (node**)malloc(size * sizeof(node*));

    int i;
    for (i=0; i<k; i++){
        int num;
        printf("Input %d th value: \n", i+1);
        scanf("%d", &num);
        add(num, hashmap, size);
    }

    printHashMap(hashmap, size);
    deleteHashMap(hashmap, size);

    return 0;
}