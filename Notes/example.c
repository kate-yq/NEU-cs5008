#include <stdio.h>  //library reference (input/output)
#include <stdlib.h> //have malloc/free
// main program
// exactly 1 main() each program
int main(){
    printf("hello world\n");
    return 0;
}

typedef struct node {
    int data;
    struct node* next;
} node_type;
