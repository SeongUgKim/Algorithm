#include <vector>
#include <cmath>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int dp[m][n];
    int mx = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i) {
        dp[i][0] = matrix[i][0] - '0';
        mx = max(dp[i][0], mx);
    }
    for (int i = 0; i < n; ++i) {
        dp[0][i] = matrix[0][i] - '0';
        mx = max(dp[0][i], mx);
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == '1') dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
            mx = max(mx, dp[i][j]);   
        }
    }
    return pow(mx, 2);
}