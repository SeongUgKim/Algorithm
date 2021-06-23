#include "stdc++.h"
using namespace std;

int solve(vector<int> nums)
{
    /*int count = 0;
    int digit = 0;
    for (auto a : nums)
    {
        digit = 0;
        while (a > 0)
        {
            a /= 10;
            digit++;
        }
        if (digit % 2 == 1)
        {
            count++;
        }
    }   
    return count;*/
    int count = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        string s = to_string(nums[i]);
        if (s.size() % 2 == 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 800, 2, 10, 3};
    cout << solve(nums) << endl;
    return 0;
}