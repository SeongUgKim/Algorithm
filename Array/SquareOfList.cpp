#include "stdc++.h"
using namespace std;

vector<int> solve(vector<int>& nums)
{
    vector<int> ret;
    ret.resize(nums.size());
    int start = 0;
    int end = nums.size() - 1;
    int i = 0;
    while (start < end)
    {
        ret[ret.size() - 1 - i] = abs(nums[start]) > abs(nums[end]) ? nums[start] * nums[start++] : nums[end] * nums[end--];
        i++;
    }
    ret[0] = nums[start] * nums[start];
    return ret;
}

int main()
{
    vector<int> nums = {-9, -2, 0, 2, 3};
    vector<int> ret = solve(nums);
    for (auto a : ret)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}