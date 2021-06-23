#include <unordered_set>
#include "stdc++.h"
using namespace std;

int thirdMax(vector<int>& nums) {
    // Sorting
    /*
    sort(nums.begin(), nums.end());
    vector<int> a;
    a.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[i - 1])
        {
            a.push_back(nums[i]);
        }
    }
    if (a.size() < 3)
    {
        return a[a.size() - 1];
    }
    return a[a.size() - 3];  
    */
    long max1 = LONG_MIN;
    long max2 = LONG_MIN;
    long max3 = LONG_MIN;
    for (int i : nums)
    {
        if (i == max1 || i == max2 || i == max3)
        {
            continue;
        }
        if (i > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = i;
        }
        else if (i > max2)
        {
            max3 = max2;
            max2 = i;
        }
        else if (i > max3)
        {
            max3 = i;
        }
    }

    return max3 == LONG_MIN ? max1 : max3;
}