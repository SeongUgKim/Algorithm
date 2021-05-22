#include <vector>
#include <climits>
using namespace std;

// Brute Force
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        sum = nums[i];
        maxSum = max(maxSum, sum);
        for (int j = i + 1; j < n; ++j)
        {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    maxSum = max(maxSum, nums[n - 1]);
    return maxSum;
}

// Dynamic Programming
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp (n, 0);
    dp[0] = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);  
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}
