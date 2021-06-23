#include "stdc++.h"
using namespace std;

vector<int> twoSum(vector<int>& nums, int begin, int end, int target)
{
    vector<int> ret;
    unordered_map<int, int> map;
    for (int i = begin; i < end; ++i)
    {
        int key = target - nums[i];
        if (map.count(key) != 0)
        {
            ret.push_back(map[key]);
            ret.push_back(i);
            continue;
        }
        map[nums[i]] = i;
    }
    return ret;
}

vector<vector<int>> solve(vector<int>& nums)
{
    vector<int> total;
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        int target = 0 - nums[i];
        vector<int> temp = twoSum(nums, i + 1, nums.size() - 1, target);
        if (temp.size() == 0)
        {
            continue;
        }
        int start = 0;
        int end = 1;
        while (start < temp.size())
        {
            total.push_back(nums[i]);
            total.push_back(temp[nums[start]]);
            total.push_back(temp[nums[end]]);
            start = end + 1;
            end = start + 1;
        }
    }
    int k = 0;
    int count = total.size() / 3;
    for (int i = 0; i < count; ++i)
    {
    }
}

int main()
{

    return 0;
}