#include <stdlib.h>
#include <stdio.h>

int maxValue(int* values, int* weights, int len, int capacity){
    int dp[capacity+1];
    int i, j;

    for (i=1; i<=capacity; i++){
        dp[i] = -1;
    }
    dp[0] = 0;

    for (i = 0; i<len; i++){
        for (j=capacity; j>= weights[i]; j--){
            if (dp[j - weights[i]] != -1){
                dp[j] = dp[j] >= dp[j - weights[i]] + values[i] ? dp[j] : dp[j - weights[i]] + values[i];
            }
        }
    }

    int maxV = 0;
    for (i=1; i<=capacity; i++){
        maxV = dp[i] >= maxV ? dp[i] : maxV;
    }
    return maxV;
}

int main(){
    int len;
    printf("Number of items: \n");
    scanf("%d", &len);

    int values[len];
    printf("Item values: \n");
    int i;
    for (i = 0; i<len; i++){
        scanf("%d", &values[i]);
    }

    int weights[len];
    printf("Item weights: \n");
    for (i = 0; i<len; i++){
        scanf("%d", &weights[i]);
    }

    int capacity;
    printf("Knapsack weight capacity: \n");
    scanf("%d", &capacity);


    printf("Answer - Maximum value: \n");
    printf("%d \n", maxValue(values, weights, len, capacity));
}