int MinimizeDifference(vector<int> nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i];
    }

    // subset sum problem
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (nums[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    int diff = INT_MAX;
    for (int i = 0; i < sum / 2; ++i)
    {
        int first = i;
        int second = sum - i;
        if (dp[n][i] == true && diff > abs(second - first))
        {
            diff = abs(second - first);
        }
    }
    return diff;
}

