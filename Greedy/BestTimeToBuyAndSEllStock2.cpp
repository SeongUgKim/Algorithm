#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int i = 0;
    int j = 1;
    int profit = 0;
    int diff;
    while (j < n)
    {
        if (prices[i] < prices[j])
        {
            diff = prices[j] - prices[i];
            profit += diff;
        }
        i++;
        j++;
    }
    return profit;
}
