#include "stdc++.h"
using namespace std;
    //topdown
    vector<int> dp;
    int topdown(int n)
    {
        int result;
        if (dp[n] != -1)
        {
            return dp[n];
        }
        if (n == 0)
        {
            result = 0;
        }
        else if (n == 1 || n == 2)
        {
            result = 1;
        }
        else
        {
            result = topdown(n - 1) + topdown(n - 2) + topdown(n - 3);
            dp[n] = result;
        }
        return result;
    }
    int tribonacci(int n) {
        dp.resize(n + 1, -1);
        return topdown(n);
    }

    //bottom_up
        int tribonacci(int n) {
        vector<int> bottom_up(n + 1, 0);
        if (n == 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }
        bottom_up[1] = 1;
        bottom_up[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            bottom_up[i] = bottom_up[i - 1] + bottom_up[i - 2] + bottom_up[i - 3];
        }
        return bottom_up[n];
    }
    