#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


// the followings are the implement of Queue
// contains only the necessary methods

typedef struct queue {
    // 0 is head, 10 is end
    int ary[10];
    int size;
}queue;

void enqueue(queue* q, int element){
    q->ary[q->size] = element;
    (q->size)++;
}

int dequeue(queue* q){
    int temp = q->ary[0];
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

void bfs(int** matrix, int size){
    bool visited[size];
    int i;
    for (i=0; i<size; i++){
        visited[i] = false;
    }

    queue* q = (queue*)malloc(sizeof(queue));
    enqueue(q, 0);
    visited[0] = true;

    while(!isEmpty(q)){
        int cur = dequeue(q);
        printf("%d ", cur);
        for (i=0; i<size; i++){
            if (matrix[cur][i] == 1 && !visited[i]){
                enqueue(q, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
    free(q);
}

int main(){
    int** matrix = (int**)malloc(9*sizeof(int*));
    int i, j;
    for (i=0; i<9; i++){
        matrix[i] = (int*)malloc(9*sizeof(int));
        for (j=0; j<9; j++){
            matrix[i][j] = 0;
        }
    }

    matrix[0][1] = 1;
    matrix[0][3] = 1;
    matrix[1][2] = 1;
    matrix[1][4] = 1;
    matrix[2][5] = 1;
    matrix[3][4] = 1;
    matrix[3][6] = 1;
    matrix[4][7] = 1;
    matrix[5][8] = 1;
    matrix[6][7] = 1;
    matrix[7][8] = 1;

    bfs(matrix, 9);

    return 0;
}