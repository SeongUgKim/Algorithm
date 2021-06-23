#include "stdc++.h"
using namespace std;

int solve(vector<int>& nums)
{
    unordered_map<int, int> mp;
    for (int a : nums)
    {
        mp[a]++;
    }

    int res = INT_MAX;
    for (int a : nums)
    {
        if (mp[a] > nums.size() / 2)
        {
            res = a;
        }
    }

    return res;
}