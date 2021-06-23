#include "stdc++.h"
using namespace std;
vector<int> solve(vector<int>& nums)
{
    /*if (nums.size() <= 2)
    {
        return nums;
    }
    if (nums.size() == 3)
    {
        swap(nums[0], nums[2]);
        return nums;
    }
    if (nums.size() == 4)
    {
        swap(nums[0], nums[2]);
        swap(nums[1], nums[3]);
        return nums;
    }
    int even = 0;
    int odd = 1;
    while (even + 2 < nums.size())
    {
        swap(nums[even], nums[even + 2]);
        even += 4;
    }
    while (odd + 2 < nums.size())
    {
        swap(nums[odd], nums[odd + 2]);
        odd += 4;
    }
    return nums;*/
    int i = 0;
    for (; i < nums.size() - nums.size() % 4; i += 4)
    {
        swap(nums[i], nums[i + 2]);
        swap(nums[i + 1], nums[i + 3]);
    }
    if (nums.size() % 4 == 3)
    {
        swap(nums[i], nums[i + 2]);
    }
    return nums;
}

int main()
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ret = solve(nums);
    for (auto& a : nums)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}