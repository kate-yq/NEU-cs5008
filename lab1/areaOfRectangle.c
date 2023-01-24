#include <stdio.h>

struct rectangle {
    int width;
    int height;
};

int areaOfRectangle(struct rectangle* rec) {
    int area = rec->width * rec->height;
    return area;
}

int main() {
    struct rectangle rec;
    printf("Width =  ");
    scanf("%d", &rec.width);
    printf("Height = ");
    scanf("%d", &rec.height);
    printf("the area of given rectangle is: %d \n", areaOfRectangle(&rec));

    return 0;
}
