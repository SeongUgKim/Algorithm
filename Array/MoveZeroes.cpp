#include "stdc++.h"
using namespace std;

void solve(vector<int>& nums)
{
    /*int start = 0;
    int end = 0;
    while (end < nums.size())
    {
        while (nums[end] == 0)
        {
            end++;
        }
        nums[start] = nums[end];
        start++;
        end++;
    }
    while (start < nums.size())
    {
        nums[start++] = 0;
    }*/
    int cur = 0;
    int slow = 0;
    while (cur < nums.size())
    {
        if (nums[cur] != 0)
        {
            swap(nums[slow++], nums[cur]);
        }
        cur++;
    }
}