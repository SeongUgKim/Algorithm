#include "stdc++.h"
using namespace std;

vector<int> dp;
int topdown(int n, vector<int>& cost)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return min(cost[0], cost[1]);
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = min(cost[n - 1] + topdown(n - 1, cost), cost[n - 2] + topdown(n - 2, cost));
}

int minCostClimbingStairs(vector<int>& cost)
{
    int n = cost.size();
    dp.resize(n + 1, -1);
    return topdown(n, cost);
}
