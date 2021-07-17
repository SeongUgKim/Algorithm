#include <vector>
using namespace std;
bool solve(vector<int>& nums) {
    int n = nums.size();
    int left[n];
    int right[n];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];
    for (int i = 1; i < n; ++i) {
        left[i] = max(left[i - 1], nums[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        right[i] = min(right[i + 1], nums[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (right[i + 1] > left[i]) return true;
    }
    return false;