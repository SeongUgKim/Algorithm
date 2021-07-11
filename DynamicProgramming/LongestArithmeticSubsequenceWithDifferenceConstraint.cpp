#include <vector>
#include <unordered_map>
using namespace std;

// Time Limit
vector<unordered_map<int, int>> dp;
int topdown(vector<int>& nums, int index, int prev, int diff) {
    if (index == nums.size()) return 0;
    if (dp[index].find(prev) != dp[index].end()) return dp[index][prev];
    if (prev == INT_MIN) return dp[index][prev] = max(topdown(nums, index + 1, nums[index], diff) + 1, topdown(nums, index + 1, prev, diff));
    if (nums[index] - prev != diff) return dp[index][prev] = topdown(nums, index + 1, prev, diff);
    return dp[index][prev] = topdown(nums, index + 1, nums[index], diff) + 1;
}
int solve(vector<int>& nums, int diff) {
    int n = nums.size();
    dp = {};
    dp.resize(n);
    return topdown(nums, 0, INT_MIN, diff);
}

// dp[i] = nums[i]가 마지막 원소이고 diff만큼의 차이를 갖고 있는 arithmetic subsequence의 길이

int bottomupSolve(vector<int>& nums, int diff) {
    int n = nums.size();
    if (n == 0) return 0;
    unordered_map<int, int> dp;
    int res = 1;
    for (int i = 0; i < n; ++i) {
        if (dp.find(nums[i] - diff) != dp.end()) {
            dp[nums[i]] = dp[nums[i] - diff] + 1;
            res = max(res, dp[nums[i]]);
        }
        else {
            dp[nums[i]] = 1;
        }
    }
    return res;
}