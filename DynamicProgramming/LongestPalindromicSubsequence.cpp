#include <vector>
#include <string>
using namespace std;
// topdown
vector<vector<int> > dp;
int topdown(string& s, int i, int j) {
    if (i == j) return 1;
    if (j - i == 1) return s[i] == s[j] ? 2 : 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j]) dp[i][j] = topdown(s, i + 1, j - 1) + 2;
    else dp[i][j] = max(topdown(s, i + 1, j), topdown(s, i, j - 1));
    return dp[i][j];
}
int longestPalindromeSubseq(string s) {
    int n = s.size();
    dp.clear();
    dp.resize(n, vector<int>(n, -1));
    return topdown(s, 0, n - 1);
}

// bottom-up
int solve(string s) {
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if (i != n - 1) {
            if (s[i] == s[i + 1]) dp[i][i + 1] = 2;
            else dp[i][i + 1] = 1;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (j - i == 1) continue;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}