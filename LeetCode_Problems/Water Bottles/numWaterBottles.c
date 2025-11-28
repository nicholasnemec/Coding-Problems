int numWaterBottles(int numBottles, int numExchange) {
    int totalDrank = numBottles;
    do{
        totalDrank += numBottles/numExchange;
        numBottles = (numBottles/numExchange) + (numBottles % numExchange);
        
    }while(numBottles >= numExchange);
    return totalDrank;
}