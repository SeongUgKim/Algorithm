#include "stdc++.h"
using namespace std;

vector<string> solve(vector<int>& nums)
{
    vector<string> ret;
    if (nums.size() == 0)
    {
        return ret;
    }
    if (nums.size() == 1)
    {
        string s = to_string(nums[0]);
        ret.push_back(s);
        return ret;
    }
    int start = 0;
    int prev = 0;
    int end = 1;
    while (end < nums.size())
    {
        if (nums[prev] + 1 != nums[end])
        {
            string s;
            if (start == prev)
            {
                s = to_string(nums[start]);
            }
            else
            {
                s = to_string(nums[start]) + "->" + to_string(nums[prev]);
            }
            ret.push_back(s);
            prev = end;
            start = end;
            end++;
            continue;
        }
        prev++;
        end++;
    }
    string s;
    if (prev == start)
    {
        s = to_string(nums[start]);
    }
    else 
    {
        s = to_string(nums[start]) + "->" + to_string(nums[prev]);
    }
    ret.push_back(s);
    return ret;
}