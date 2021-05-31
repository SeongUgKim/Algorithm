#include <vector>
using namespace std;
bool canPartition(int start, vector<int>& nums, int used[], int k, int progressBucketSum, int targetSum)
{
    if (k == 1)
    {
        return true;
    }
    if (progressBucketSum == targetSum)
    {
        return canPartition(0, nums, used, k - 1, 0, targetSum);
    }
    for (int i = start; i < nums.size(); ++i)
    {
        if (!used[i])
        {
            used[i] = 1;
            if (canPartition(i + 1, nums, used, k, progressBucketSum + nums[i], targetSum))
            {
                return true;
            }
            used[i] = 0;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i];
    }
    if (k == 0 || sum % k != 0)
    {
        return false;
    }
    int used[n];
    for (int i = 0; i < n; ++i)
    {
        used[i] = 0;
    }
    return canPartition(0, nums, used, k, 0, sum / k);
}

