#include "stdc++.h"
using namespace std;

int binarySearch(vector<int>& nums,int num)
{
    int l = 0;
    int r = nums.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == num)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (nums[mid] > num)
        {
            r = mid - 1;
        }
        else 
        {
            l = mid + 1;
        }
    }
    return ans;
}

int solve(vector<int>& nums) {
    /*unordered_set<int> st;
    for (int n : nums)
    {
        st.insert(n);
    }
    return st.size();*/

    int i = 0;
    int count = 0;
    while (i < nums.size())
    {
        count++;
        i = binarySearch(nums, nums[i]) + 1;
    }
    return count;
}