#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
}node;

typedef struct graph {
    int numberOfNodes;
    struct node** adjlist;
}graph;

void printAdjList(struct graph *g){
    int n = g->numberOfNodes;
    int i;
    for (i=0; i<n; i++){
        printf("%d: ", i);
        struct node* itr = g->adjlist[i];
        while(itr != NULL){
            printf("%d -> ", itr->value);
            itr = itr->next;
        }
        printf("NULL\n");
    }
}


int main(){
    int adjmatrix[4][4];
    int i,j;

    for (i = 0; i<4; i++){
        for (j=0; j<4; j++){
            adjmatrix[i][j] = 0;
        }
    }
    adjmatrix[0][1] = 1;
    adjmatrix[0][2] = 1;
    adjmatrix[1][2] = 1;
    adjmatrix[2][0] = 1;
    adjmatrix[3][2] = 1;

    printf("Adjacency Matrix:\n");
    for (i = 0; i<4; i++){
        for (j=0; j<4; j++){
            printf("%d ", adjmatrix[i][j]);
        }
        printf("\n");
    }

    struct graph* g = (graph*)malloc(sizeof(graph));
    g->numberOfNodes = 4;
    g->adjlist = (node**)malloc(4*sizeof(node*));

    printf("Adjacency List:\n");
    for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            // edge from i to j
            if (adjmatrix[i][j] == 1){
                struct node* cur = (node*)malloc(sizeof(node));
                cur->value = j;

                if (g->adjlist[i] == NULL){
                    g->adjlist[i] = cur;
                } else {
                    cur->next = g->adjlist[i];
                    g->adjlist[i] = cur;
                }
                
            }
        }
    }

    printAdjList(g);

    free(g->adjlist);
    free(g);
    return 0;
}