#include "stdc++.h"
using namespace std;

bool solve(vector<int>& nums, int k)
{
    int maxDiff = 0;
    unordered_map<int, int> mp;
    int dup = INT_MAX;
    for (int a : nums)
    {
        if (++mp[a] > 1)
        {
            dup = a;
            break;
        }
    }
    if (dup == INT_MAX)
    {
        return false;
    }
    mp.clear();
    for (int i = 0; i < nums.size(); ++i)
    {
        if (mp.count(nums[i]))
        {
            maxDiff = max(maxDiff, abs(i - mp[nums[i]]));
        }
        mp[nums[i]] = i;
    }
    return k <= maxDiff;
}