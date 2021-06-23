#include "stdc++.h"
using namespace std;

int solve(vector<int> nums)
{
    int res = 0;
    unordered_map<int, int> mp;
    for (int a : nums)
    {
        mp[a]++;
    }

    for (int a : nums)
    {
        if (mp[a] == 2)
        {
            res = a;
            break;
        }
    }
    return res;
}