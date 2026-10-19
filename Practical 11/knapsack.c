#include <stdio.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int N, W;
    
    // Read number of items
    scanf("%d", &N);

    int values[N], weights[N];

    // Read values
    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    // Read weights
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    // Read capacity
    scanf("%d", &W);

    // Calculate max value
    int result = knapsack(weights, values, N, W);

    // Print result
    printf("%d\n", result);

    return 0;
}