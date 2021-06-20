vector<int> dp;
int topdown(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int left = i;
        int right = n - i - 1;
        if (left == 0) sum += topdown(right);
        else if (right == 0) sum += topdown(left);
        else sum += topdown(left)  *  topdown(right);
    }
    return dp[n] = sum;
}
int numTrees(int n) {
    dp = {};
    dp.resize(n + 1, -1);
    return topdown(n);
}
};

