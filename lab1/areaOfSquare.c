#include <stdio.h>

struct square {
    int side;
};

int areaOfSquare(struct square* sq) {
    return sq->side * sq->side;
}

int main(){
    struct square sq;
    printf("side length = ");
    scanf("%d", &sq.side);
    printf("The area of this square is: %d \n", areaOfSquare(&sq));

    return 0;
}