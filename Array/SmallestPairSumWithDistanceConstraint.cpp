#include <vector>
using namespace std;
int solve(vector<int>& nums) {
    int n = nums.size();
    int cur = nums[0];
    int res = INT_MAX;
    for (int i = 2; i < n; ++i) {
        res = min(res, cur + nums[i]);
        cur = min(cur, nums[i - 1]);
    }
    return res;
}