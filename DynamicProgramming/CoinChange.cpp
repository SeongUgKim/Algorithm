// dp[i][j] = 0 부터 i까지의 코인으로 amount를 만들 수 있는 최소한의 코인 개수
// dp[i][j] = min(1 + dp[i][j - amount - coins[i - 1]], dp[i - 1][j])
#include <vector>
using namespace std;
// topdown
vector<vector<int>> dp;
int topdown(vector<int>& coins, int i, int amount) {
    if (i == coins.size()) {
        if (amount > 0) return 1e5;
    }
    if (amount == 0) return 0;
    if (dp[i][amount] != -1) return dp[i][amount];
    if (coins[i] > amount) return dp[i][amount] = topdown(coins, i + 1, amount);
    return dp[i][amount] = min(topdown(coins, i + 1, amount), 1 + topdown(coins, i, amount - coins[i]));
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    dp.clear();
    dp.resize(n, vector<int>(amount + 1, -1));
    return topdown(coins, 0, amount) > 1e4 ? -1 : topdown(coins, 0, amount);
}

// bottomup
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= amount; ++j) {
            if (i == 0 && j > 0) dp[i][j] = 1e5;
            else if (j == 0) dp[i][j] = 0;
            else if (coins[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
        }
    }
    return dp[n][amount] > 1e4 ? -1 : dp[n][amount];
}