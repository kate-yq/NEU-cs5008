#include <stdio.h>

int main() {
    int i;
    printf("Please select: \n1: add\n2: deduct\n3: product\n4: divide\n5: exit\n");
    scanf("%d", &i);
    while(i < 5){
        int num1;
        int num2;
        printf("First number: ");
        scanf("%d", &num1);
        printf("Second number: ");
        scanf("%d", &num2);
        switch(i){
            case 1:
                printf("%d\n", num1+num2);
                break;
            case 2:
                printf("%d\n", num1-num2);
                break;
            case 3:
                printf("%d\n", num1*num2);
                break;
            case 4:
                if (num2 == 0){
                    printf("the divider cannot equal to 0");
                    break;
                }
                printf("%d\n", num1/num2);
                break;
            default:
                break;
        }
        printf("Please select: \n1: add\n2: deduct\n3: product\n4: divide\n5: exit\n");
        scanf("%d", &i);
    }
    return 0;
}