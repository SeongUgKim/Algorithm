#include "stdc++.h"
using namespace std;

int solve(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int i = nums.size() / 2;
    int j = i - 1 ;
    return nums[i] - nums[j];
}

int main()
{
    vector<int> nums = {1, 9, 7, 4, 3, 6};
    cout << solve(nums) << endl;
    return 0;
}