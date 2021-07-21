#include <vector>
using namespace std;
int solve(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int len = n - k;
    int res = INT_MAX;
    for (int i = 0; i + (len - 1) < n; ++i) {
        res = min(res, nums[i + len - 1] - nums[i]);
    }
    return res;
}