#include "stdc++.h"
using namespace std;

int solve(vector<int>& nums)
{
    //sorting
    /* O(NlogN) / O(1)
    sort(nums.begin(), nums.end());
    int i = 0;
    if (nums[i] != 0)
    {
        return 0;
    }
    for (; i < nums.size() - 1; ++i)
    {
        if (nums[i] + 1 != nums[i + 1])
        {
            return nums[i] + 1;
        }
    }
    return nums[i] + 1;
    */
   // boolean vector O(N) / O(N)
   /*
   vector<bool> a(nums.size() + 1, false);
   for (int n : nums)
   {
       a[n] = true;
   }
   int ret = -1;
   for (int i = 0; i < a.size(); ++i)
   {
       if (a[i] == false)
       {
           ret = i;
       }
   }
   return ret;
   */
  // Bit Masking
    /*
    int missNum = nums.size();
    for (int i = 0; i < nums.size(); ++i)
    {
        missNum ^= i ^ nums[i];
    }
    return missNum;
    */
   // Summation
    int expect = (nums.size() + 1) * nums.size() / 2;
    int sum = 0;
    for (int a : nums)
    {
        sum += a;
    }
    return expect - sum;
}