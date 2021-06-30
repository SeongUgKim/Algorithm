#include <vector>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int minVal = INT_MAX;
    int dp[n][n];
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; ++i) dp[i][0] = dp[i - 1][0] + triangle[i][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        minVal = min(dp[n - 1][i], minVal);
    }
    return minVal;
}