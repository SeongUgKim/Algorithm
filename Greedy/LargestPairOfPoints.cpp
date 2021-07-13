#include <vector>
using namespace std;
int solve(vector<int>& nums, vector<int>& values) {
    int n = nums.size();
    int sub = INT_MIN;
    int res = INT_MIN;
    for (int i = 0; i < n; ++i) {
        sub = max(sub, values[i] - nums[i]);
        res = max(res, values[i] + nums[i] + sub);
    }
    return res;
}