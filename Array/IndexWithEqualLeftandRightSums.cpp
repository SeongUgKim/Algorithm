#include <vector>
using namespace std;
int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }
    int leftSum = 0;
    int rightSum = accumulate(nums.begin(), nums.end(), 0) - nums[0];
    if (leftSum == rightSum)
    {
        return 0;
    }
    for (int i = 1; i < n; ++i)
    {
        leftSum += nums[i - 1];
        rightSum -= nums[i];
        if (leftSum == rightSum)
        {
            return i;
        }
    }
    return -1;
}

