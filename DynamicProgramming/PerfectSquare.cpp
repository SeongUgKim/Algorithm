#include <vector>
#include <cmath>
using namespace std;
// brute force (accepted)
vector<vector<int>> dp;
int topdown(int n, int num) {
    if (n - pow(num, 2) < 0) return -1;
    if (n - pow(num, 2) == 0) return 1;
    if (dp[n][num] != -2) return dp[n][num];
    int temp1 = topdown(n - pow(num , 2), num);
    int temp2 = topdown(n, num + 1);
    if (temp1 == -1 && temp2 == -1) return dp[n][num] = -1;
    if (temp1 == -1) return dp[n][num] = temp2;
    if (temp2 == -1) return dp[n][num] = temp1 + 1;
    if (temp1 < temp2) return dp[n][num] = temp1 + 1;
    return dp[n][num] = temp2;
}
int numSquares(int n) {
    int sqrt_num = sqrt(n);
    dp.clear();
    dp.resize(n + 1, vector<int>(sqrt_num + 1, -2));
    return topdown(n, 1);
}

// topdown
vector<int> dp1;
int topdown(int n) {
    if (n <= 3) return n;
    if (dp1[n] != -1) return dp1[n];
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; ++i) {
        ans = min(ans, 1 + topdown(n - (i * i)));
    }
    return dp1[n] = ans;
}
int numSquares(int n) {
    int sqrt_num = sqrt(n);
    dp1.clear();
    dp1.resize(n + 1, -1);
    return topdown(n);
}

// bottom-up
int numSquares(int n) {
    int dp[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = i;
        if (i <= 3) continue;
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
        }
    }
    return dp[n];
}