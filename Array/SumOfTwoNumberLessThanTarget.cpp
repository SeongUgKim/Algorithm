#include <vector>
using namespace std;
int solve(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    int max_val = INT_MIN;
    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum >= target) j--;
        else {
            i++;
            max_val = max(max_val, sum);
        }
    }
    return max_val;
}