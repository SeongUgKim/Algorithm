#include <vector>
#include <string>
using namespace std;
// topdown
vector<vector<vector<int>>> dp;
int topdown(vector<string>& strs, int i, int m, int n) {
    int len = strs.size();
    if (i == len) return 0;
    if(dp[i][m][n] != -1) return dp[i][m][n];
    string curr = strs[i];
    int one = 0;
    int zero = 0;
    int k = curr.size();
    for (int j = 0; j < k; ++j) {
        if (curr[j] == '0') zero++;
        if (curr[j] == '1') one++;
    }
    if (zero > m || one > n) return dp[i][m][n] = topdown(strs, i + 1, m, n);
    return dp[i][m][n] = max(topdown(strs, i + 1, m - zero, n - one) + 1, topdown(strs, i + 1, m, n));
}
int findMaxForm(vector<string>& strs, int m, int n) {
    int l = strs.size();
    dp.clear();
    dp.resize(l, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return topdown(strs, 0, m, n);
}