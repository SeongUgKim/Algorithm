int numWaterBottles(int numBottles, int numExchange) {
    int sum = 0;
    int remainder = 0;
    while (numBottles > 0)
    {
        sum += numBottles;
        numBottles += remainder;
        remainder = numBottles % numExchange;
        numBottles /= numExchange;
    }
    return sum;
}
