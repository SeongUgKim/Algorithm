#include <vector>
using namespace std;
// TOPDOWN
int topdown(vector<int>& nums, int pos, int sum, int target, int dp[][2001])
{
    int n = nums.size();
    if (pos == n)
    {
        if (sum == target)
        {
            return 1;
        }
        return 0;
    }
    if (dp[pos][sum + 1000] != -1)
    {
        return dp[pos][sum + 1000];
    }
    return dp[pos][sum + 1000] = topdown(nums, pos + 1, sum + nums[pos], target, dp) + topdown(nums, pos + 1, sum - nums[pos], target, dp);
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int dp[n][2001];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 2001; ++j)
        {
            dp[i][j] = -1;
        }
    }
    return topdown(nums, 0, 0, target, dp);
}