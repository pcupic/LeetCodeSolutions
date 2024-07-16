int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize){
    int n = pricesSize;
    int minSoFar = INT_MAX;
    int profit = 0;
    for(int i = 0; i < n; i++) {
        if(minSoFar > prices[i]) {
            minSoFar = prices[i];
        }
        profit = max(profit, prices[i] - minSoFar);
    }

    return profit;
}
