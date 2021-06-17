#include <vector>
using namespace std;
int largestSumAfterKNegations(vector<int>& nums, int k) {
    int m = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] < 0)
        {
            m++;
        }
    }
    sort(nums.begin(), nums.end());
    int sum = 0;
    if (k == m)
    {
        for (int i = 0; i < m; ++i)
        {
            nums[i] *= -1;
        }
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
        }
    }
    else if (k < m)
    {
        for (int i = 0; i < k; ++i)
        {
            nums[i] *= -1;
        }
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
        }
    }
    else
    {

        for (int i = 0; i < m; ++i)
        {
            nums[i] *= -1;
            k--;
        }
        if (k % 2 == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                sum += nums[i];
            }
        }
        else
        {
            sort(nums.begin(), nums.end());
            nums[0] *= -1;
            for (int i = 0; i < n; ++i)
            {
                sum += nums[i];
            }
        }
    }
    return sum;
}
