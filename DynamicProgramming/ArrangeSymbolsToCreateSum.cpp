#include <vector>
#include <unordered_map>
using namespace std;
vector<unordered_map<int, int>> dp;

int topdown(vector<int>& nums, int target, int i)
{
    if (i < 0)
    {
        if (target == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[i].count(target))
    {
        return dp[i][target];
    }
    return dp[i][target] = topdown(nums, target - nums[i], i - 1) + topdown(nums, target + nums[i], i - 1);
}
int solve(vector<int>& nums, int target) {
    int n = nums.size();
    dp.clear();
    dp.resize(n);
    return topdown(nums, target, n - 1);
}