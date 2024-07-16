int maxProfit(int* prices, int pricesSize){
    int n = pricesSize;
    
    int profit = 0;
    for(int i = 1; i < n; i++) {
        if(prices[i] > prices[i - 1])   
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}
