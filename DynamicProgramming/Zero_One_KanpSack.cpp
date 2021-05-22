#include <vector>
class Knapsack {
public:
    vector<vector<int>> dp;
    int knapsackRecursive(vector<int>& wt, vector<int>& profit, int w, int n)
    {
        if (w == 0 || n == 0)
        {
            return 0;
        }
        if (wt[n] > w)
        {
            return knapsackRecursive(wt, profit, w, n - 1);
        }
        return max(knapsackRecursive(wt, profit, w, n - 1), profit[n] + knapsackRecursive(wt, profit, w - wt[n], n - 1));
    }

    int knapsackMemoization(vector<int>& wt, vector<int>& profit, int w, int n)
    {
        dp.clear();
        dp.resize(w + 1, vector<int>(n + 1, -1));
        if (w == 0 || n == 0)
        {
            return 0;
        }
        if (dp[w][n] != -1)
        {
            return dp[w][n];
        }
        int result;
        if (wt[n] > w)
        {
            result = knapsackMemoization(wt, profit, w, n - 1);
        }
        else
        {
            result = max(knapsackMemoization(wt, profit, w, n - 1), profit[n] + knapsackMemoization(wt, profit, w - wt[n], n - 1));
        }
        return dp[w][n] = result;
    }
    int knapsackTabulation(vector<int>& wt, vector<int>& profit, int w, int n)
    {
        dp.clear();
        dp.resize(n + 1, vector<int>(w + 1, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (wt[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i - 1][j - wt[i - 1]]);
                }
            }
        }
    }
};



