#include "stdc++.h"
using namespace std;

int solve(vector<int>& prices)
{
    // Kadane's algorithm
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); ++i)
    {
        minPrice = min(prices[i], minPrice);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;

}