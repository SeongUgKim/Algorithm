#include <vector>
using namespace std;
int solve(vector<int>& nums) {
    int maxVal = INT_MIN;
    nums.push_back(0);
    nums.push_back(100001);
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i < n - 1;  ++i)
    {
        maxVal = max(nums[i + 1] - nums[i - 1] - 1, maxVal);
    }
    return maxVal;
}
