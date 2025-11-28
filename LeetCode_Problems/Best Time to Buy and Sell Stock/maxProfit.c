int maxProfit(int* prices, int pricesSize) {
    int lowest = prices[0];
    int profit = 0;
    for(int i = 1; i < pricesSize; i++){
        if(prices[i] - lowest > profit){
            profit = prices[i] - lowest;
        }
        if(prices[i] < lowest){
            lowest = prices[i];
        }
    }
    return profit;
}