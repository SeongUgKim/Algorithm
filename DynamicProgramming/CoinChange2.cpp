// dp[i][amount] = 0 부터 i까지의 coin들로 amount를 만들 수 있는 경우의 수
// dp[i][amount] = topdown(coins, i, amount - coins[i]) + topdown(coins, i + 1, amount)
#include <vector>
using namespace std;
// topdown
vector<vector<int>> dp;
int topdown(vector<int>& coins, int i, int amount) {
    if (i == coins.size()) {
        if (amount > 0) return 0;
    }
    if (amount == 0) return 1;
    if (dp[i][amount] != -1) return dp[i][amount];
    if (coins[i] > amount) return dp[i][amount] = topdown(coins, i + 1, amount);
    return dp[i][amount] = topdown(coins, i + 1, amount) + topdown(coins, i, amount - coins[i]);
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    dp.clear();
    dp.resize(n, vector<int>(amount + 1, -1));
    return topdown(coins, 0, amount);
}

// bottom up
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= amount; ++j) {
            if (i == 0) {
                if (j > 0) dp[i][j] = 0;
            }
            else if (j == 0) dp[i][j] = 1;
            else if (coins[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
        }
    }
    return dp[n][amount];
}