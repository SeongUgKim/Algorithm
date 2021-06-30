#include <vector>
using namespace std;
// bottom-up
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < m; ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

// topdown
vector<vector<int>> dp;
int topdown(vector<vector<int>>& grid, int i , int j) {
        if (i == 0 && j == 0) return grid[i][j];
        if (i == 0) return topdown(grid, i, j - 1) + grid[i][j];
        if (j == 0) return topdown(grid, i - 1, j) + grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min(topdown(grid, i - 1, j), topdown(grid, i, j - 1)) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.clear();
        dp.resize(n, vector<int>(m, -1));
        return topdown(grid, n - 1, m - 1);
    }