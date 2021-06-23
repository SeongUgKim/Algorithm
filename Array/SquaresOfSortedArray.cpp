#include "stdc++.h"
using namespace std;

vector<int> solve(vector<int>& nums)
{
/*    vector<int> ret;
    for (int a : nums)
    {
        ret.push_back(a * a);
    }
    sort(ret.begin(), ret.end());
    return ret;*/
    vector<int> ret(nums.size());
    int i = 0;
    int j = nums.size() - 1;
    for (int k = ret.size() - 1; k >= 0; --k)
    {
        ret[k] = abs(nums[i]) > abs(nums[j]) ? nums[i] * nums[i++] : nums[j] * nums[j--];
    }
    return ret;
}

int main()
{
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ret = solve(nums);
    for (int a : ret)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}