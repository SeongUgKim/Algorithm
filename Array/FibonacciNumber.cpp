#include "stdc++.h"
using namespace std;

    //dynamic programming bottom up
    int fib(int n) 
    {
        if (n < 2)
        {
            return n;
        }
        vector<int> a(n + 1, 0);
        a[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            a[i] = a[i - 1] + a[i-2];
        }
        return a[n];
    }
    // recurssion
    int fib(int n)
    {
        if (n < 2)
        {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

    // topdown
    vector<int> dp;
    int topdown(int n)
    {
        int result = -1;
        if (dp[n] != -1)
        {
            return dp[n];
        }
        if (n < 2)
        {
            result = n;
        }
        else 
        {
            result = topdown(n - 1) + topdown(n - 2);
            dp[n] = result;
        }
        return result;
    }
    int fib(int n) {
        dp.resize(n + 1, -1);
        return topdown(n);
    }

    

