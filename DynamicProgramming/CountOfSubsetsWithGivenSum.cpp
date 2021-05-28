#include <vector>
using namespace std;
int topdown (vector<int>& set, int pos, int n, int sum, int S, vector<vector<int>> dp)
{
    if (pos == n)
    {
        if (sum == S)
        {
            return 1;
        }
        return 0;
    }
    if (dp[pos][sum] != -1)
    {
        return dp[pos][sum];
    }
    if (set[pos] > sum)
    {
        return dp[pos][sum] = topdown(set, pos + 1, n, sum, S, dp);
    }
    return dp[pos][sum] = topdown(set, pos + 1, sum, S, dp) + topdown(set, pos + 1, sum - set[pos], S, dp);
}
// A recursive solution
int countSubsetRecursive(vector<int>& set, int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (set[n - 1] > sum)
    {
        return countSubset(set, n - 1, sum);
    }
    return countSubset(set, n - 1, sum) + countSubset(set, n - 1, sum - set[n - 1]);
}


// Tabulation solution
int countSubset(vector<int>& set, int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < sum + 1; ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (set[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][sum - set[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

