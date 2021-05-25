#include <vector>
using namespace std;
// Topdown solution
vector<vector<int>> dp;
int topdown(vector<int>& nums, int n, int sum)
{
    if (sum == 0)
    {
        return dp[n][sum] = 1;
    }
    if (n == 0)
    {
        return dp[n][sum] = 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (sum < nums[n - 1])
    {
        return dp[n][sum] = topdown(nums, n - 1, sum);
    }
    return dp[n][sum] = topdown(nums, n - 1, sum) || topdown(nums, n - 1, sum - nums[n - 1]);
}
bool canPartitionTopdown(vector<int>& nums)
{
    int sum = 0;
    for (auto a : nums)
    {
        sum += a;
    }
    if (sum % 2 == 1)
    {
        return false;
    }
    sum /= 2;
    int n = nums.size();
    dp.clear();
    dp.resize(n + 1, vector<int>(sum + 1, -1));
    return topdown(nums, n, sum);
}


// Bottom Up solution
bool canPartitionBottomUp(vector<int>& nums)
{
    int sum = 0;
    for (auto a : nums)
    {
        sum += a;
    }
    if (sum % 2 == 1)
    {
        return false;
    }
    sum /= 2;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (j < nums[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][sum];
}


