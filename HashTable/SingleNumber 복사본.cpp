#include "stdc++.h"
using namespace std;

int solve(vector<int> nums)
{
    // Map solution
    /*unordered_map<int,int> mp;
    for (int a : nums)
    {
        mp[a]++;
    }

    int res = 0;
    for (int a : nums)
    {
        if (mp[a] == 1)
        {
            res = a;
        }
    }

    return res;*/
    

    // bitwise solution
    int res = 0;
    for (int a : nums)
    {
        res ^= a;
    }
    return res;
}