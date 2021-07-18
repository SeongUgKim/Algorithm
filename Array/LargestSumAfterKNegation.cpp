#include <vector>
using namespace std;
int solve(vector<int>& nums, int k) {
    int n = nums.size();
    sort (nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        if (k == 0) break;
        if (nums[i] >= 0) break;
        nums[i] *= -1;
        k--;
    }
    if (k != 0 && k % 2 == 1) {
        sort(nums.begin(), nums.end());
        nums[0] *= -1;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
    }
    return sum;
}