int RecursiveSolution(vector<int>& nums, int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (nums[n - 1] > sum)
    {
        return RecursiveSolution(nums, n - 1, sum);
    }
    return RecursiveSolution(nums, n - 1, sum) + RecursiveSolution(nums, n - 1, sum - nums[n - 1]);

}
int getNumberofSubsetWithGivenDiff(vector<int>& nums, int diff)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i];
    }
    int s1 = (diff + sum) / 2;
    int dp[n + 1][s1 + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < s1 + 1; ++j)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (nums[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][s1];
}

