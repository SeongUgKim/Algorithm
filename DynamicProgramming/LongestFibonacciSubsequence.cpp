#include <vector>
#include <unordered_map>
using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0;
    unordered_map<int, int> mp;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    mp[nums[0]] = 0;
    int res = 2;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (mp.count(nums[j] - nums[i])) {
                int k = mp[nums[j] - nums[i]];
                dp[i][j] = dp[k][i] + 1;
            }
            res = max(res, dp[i][j]);
        }
        mp[nums[i]] = i;
    }
    return (res > 2) * res;
}