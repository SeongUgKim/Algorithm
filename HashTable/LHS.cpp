#include "stdc++.h"
#include <unordered_set>
using namespace std;

int solve(vector<int>& nums)
{
    /*int key1 = 0;
    int key2 = 0;
    int length = 0;
    int maxLength = 0;
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (st.count(nums[i]))
        {
            continue;
        }
        key1 = nums[i] + 1;
        key2 = nums[i] - 1;
        if (st.count(key1))
        {
            length = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (nums[j] == key1 || nums[j] == nums[i])
                {
                    length++;
                }
            }
            maxLength = max(maxLength, length);
        }
        if (st.count(key2))
        {
            length = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (nums[j] == key2 || nums[j] == nums[i])
                {
                    length++;
                }
            }
            maxLength = max(maxLength, length);
        }
        st.insert(nums[i]);
    }
    return maxLength;*/
    int result = 0;
    map<int, int> mp;
    for (int a : nums)
    {
        mp[a]++;
    }
    int keyprev = -1;
    int prevVal = 0;
    for (auto [key, value] : mp)
    {
        if (key - keyprev == 1)
        {
            result += max(result, prevVal + value);
        }
        keyprev = key;
        prevVal = value;
    }
    return result;
}

int main()
{
    vector<int> nums = {1,3,2,2,5,2,3,7};
    cout << solve(nums) << endl;
    return 0;
}