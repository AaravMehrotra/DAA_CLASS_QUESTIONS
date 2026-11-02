#include <stdio.h>
int knapsack(int wt[], int val[], int n, int W){
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= W; w++){
            if (i == 0 || w == 0){
                dp[i][w] = 0;}
            else if (wt[i - 1] <= w){
                int take = val[i - 1] +
                           dp[i - 1][w - wt[i - 1]];
                int skip = dp[i - 1][w];
                dp[i][w] = (take > skip) ? take : skip;}
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];}
int main(){
    int wt[] = {3, 2, 1};
    int val[] = {60, 40, 30};
    int n = 3;
    int W = 5;
    int maxValue = knapsack(wt, val, n, W);
    printf("Maximum value = %d\n", maxValue);
    return 0;}