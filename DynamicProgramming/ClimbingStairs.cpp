#include <vector>
using namespace std;
// Topdown
vector<int> dp;
int topdown(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (dp[n] != -1) return dp[n];
    return dp[n] = topdown(n - 1) + topdown(n - 2);
}
int climbStairs(int n) {
    dp.clear();
    dp.resize(n + 1, -1);
    return topdown(n);
}

// Bottom-Up
int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}