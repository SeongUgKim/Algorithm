#include "stdc++.h"
using namespace std;

vector<int> dp;
int topdown(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = topdown(n - 1) + topdown(n -2);
}


int climbStairs(int n)
{
    dp.resize(n + 1, -1);
    return topdown(n);
}

int main()
{
    int n = 45;
    cout << climbStairs(n) << endl;
    return 0;
}