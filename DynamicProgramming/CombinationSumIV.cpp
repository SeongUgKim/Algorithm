#include <vector>
using namespace std;
vector<int> dp;
int topdown(vector<int>& nums, int target) {
    if (target == 0) return 1;
    if (dp[target] != -1) return dp[target];
    int res = 0;
    for (int i : nums) {
        if (i <= target) res += topdown(nums, target - i);
    }
    return dp[target] = res;
}
int combinationSum4(vector<int>& nums, int target) {
    dp.clear();
    dp.resize(target + 1, -1);
    topdown(nums, target);
    return dp[target];
}