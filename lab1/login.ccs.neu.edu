#include <stdio.h>
#include <math.h>

struct circle {
    int radius;
};

double areaOfCircle(struct circle* c){
    return M_PI*(c->radius)*(c->radius);
}

int main(){
    struct circle c;
    printf("radius = ");
    scanf("%d", &c.radius);
    printf("The area of this circle is: %.2lf\n", areaOfCircle(&c));

    return 0;
}