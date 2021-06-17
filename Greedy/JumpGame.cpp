#include <vector>
using namespace std;
// dp
bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n + 1, false);
    dp[n - 1] = true;
    for (int i = n - 2; i >= 0; --i)
    {
        int number = nums[i];
        for (int j = 0; j <= number; ++j)
        {
            dp[i] = dp[i] || dp[i + j];
            if (dp[i] == true)
            {
                break;
            }
        }
    }
    return dp[0];
}

// O(N)
bool canJump(vector<int>& nums) {
    int reachable = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (reachable < i)
        {
            return false;
        }
        reachable = max(reachable, i + nums[i]);
    }
    return true;
}