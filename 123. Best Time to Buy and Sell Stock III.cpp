int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxProfit(int* prices, int pricesSize){

    int n = pricesSize;
    if( n < 2)
        return 0;
    
    int *left = (int*)calloc(n, sizeof(int));
    int *right = (int*)calloc(n, sizeof(int));

    int p1 = prices[0];
    int p2 = prices[n - 1];

    for(int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], prices[i] - p1);
        p1 = min(p1, prices[i]);

        int j = n - 1 - i;

        right[j] = max(right[j + 1], p2 - prices[j]);
        p2 = max(p2, prices[j]);
    }
    int profit = 0;
    for(int i = 0; i < n; i++) {
        profit = max(profit, left[i] + right[i]);
    }

    return profit;
}
