#include <vector>
using namespace std;
// A recursive solution for subset sum problem
bool isSubsetSumRecursive(vector<int>& set, int n, int sum) {
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (set[n] > sum)
    {
        return isSubsetSum(set, n - 1, sum);
    }
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}


// A Dynamic Programming solution for subset sum problem.
bool isSubsetSumDP(vector<int>& set, int n, int sum)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i < sum + 1; ++i)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (j < set[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }
    return dp[n][sum];
}
