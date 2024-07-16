int coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0) return 0;

    int dp[amount + 1];
    for (int i = 0; i <= amount; ++i) {
        dp[i] = INT_MAX - 1; 
    }
    dp[0] = 0; 

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coinsSize; ++j) {
            if (coins[j] <= i) {
                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
    }

    return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
}
