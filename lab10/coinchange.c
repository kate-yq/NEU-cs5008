#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// arr of coin value
// a total value
// return the minimum number of coins to represent the value

int find(int* coins, int len, int* memo, int cur, int value){
    if (memo[cur] < value+1){
        return memo[cur];
    }
    int i;
    for (i=0; i<len; i++){
        if (cur >= coins[i]){
            int num = find(coins, len, memo, cur-coins[i], value)+1;
            memo[cur] = memo[cur] > num? num : memo[cur];
        }
    }
    return memo[cur];
}


int coinChange(int* coins, int len, int value){
    int memo[value+1];
    int i,j;

    memo[0] = 0;

    for (i=1; i<=value; i++){
        memo[i] = value+1;
    }

    memo[value] = find(coins, len, memo, value, value);

    return memo[value] >= value+1? -1 : memo[value];
}

int main(){
    int len;
    printf("Number of values of coins: \n");
    scanf("%d", &len);

    int coins[len];
    printf("Coins: \n");
    int i;
    for (i = 0; i<len; i++){
        scanf("%d", &coins[i]);
    }

    int value;
    printf("Amount: \n");
    scanf("%d", &value);


    printf("Answer: \n");
    printf("%d \n", coinChange(coins, len, value));
}