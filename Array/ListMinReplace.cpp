#include "stdc++.h"
using namespace std;

vector<int> solve(vector<int>& nums)
{
    vector<int> ret;
    if (nums.size() == 0)
    {
        return ret;
    }
    if (nums.size() == 1)
    {
        ret.push_back(0);
        return ret;
    }
    ret.resize(nums.size());
    ret[0] = 0;
    ret[1] = nums[0];
    int minNum = ret[1];
    for (int i = 2; i < ret.size(); ++i)
    {
        minNum = min(minNum, nums[i - 1]);
        ret[i] = minNum;
    }
    return ret;
}

int main()
{
    vector<int> nums = {10, 5, 7, 9};
    vector<int> ret = solve(nums);
    for (auto& a : ret)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}