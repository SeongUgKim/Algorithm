#include "stdc++.h"
using namespace std;

int solve(vector<int>& nums)
{
    vector<int> v(nums);
    sort(v.begin(), v.end());
    int k = 0;
    int l = -1;
    int r = -1;
    for (int i = 0; i < v.size(); ++i)
    {
        if (nums[i] != v[i])
        {
            if (k == 0)
            {
                l = i;
                k++;
            }
            else 
            {
                r = i;
            }
        }
    }
    if (l == -1 && r == -1)
    {
        return 0;
    }
    return r - l + 1;
}

int main()
{
    vector<int> nums = {0, 1, 4, 3, 8, 9};
    cout << solve(nums) << endl;
    return 0;
}