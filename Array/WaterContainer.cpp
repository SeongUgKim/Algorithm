#include "stdc++.h"
using namespace std;

int solve(vector<int>& height)
{
    //Brute force
    int n = height.size();
    int maxarea = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            maxarea = max(maxarea, min(height[i], height[j]) * (j - i));
        }
    }
    return maxarea;  
    // Two pointer
    int i = 0;
    int j = height.size() - 1;
    int ans = 0;
    while (i < j)
    {
        ans = max(ans, min(height[i], height[j]) * (j - i));
        height[i] > height[j] ? j-- : i++;
    }      
    return ans;
}

int main(void)
{
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    cout << solve(nums) << endl;
    return 0;
}