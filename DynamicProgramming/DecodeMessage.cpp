#include <vector>
#include <string>
#include <utility>
using namespace std;
// bottom up
int solve(string message) {
    int n = message.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; 
    dp[1] = message[0] == '0' ? 0 : 1;
    for (int i = 2; i <= n; ++i) {
        int num = stoi(message.substr(i - 2, 2));
        if (message[i - 1] != '0') dp[i] = dp[i - 1];
        if (num >= 10 && num <= 26) dp[i] += dp[i - 2];
    }
    return dp[n];
}

// topdown
vector<int> dp;
int topdown(string& message, int index) {
    if (index < 0) return 1;
    if (index == 0) {
        if (message[index] != '0') return 1;
        return 0;
    }
    if (message[index] == '0') dp[index] = 0;
    else dp[index] = topdown(message, index - 1);
    int num = stoi(message.substr(index - 1, 2));
    if (num >= 10 && num <= 26) dp[index] += topdown(message, index - 2);
    return dp[index];
}
int solve(string message) {
    int n = message.size();
    dp = {};
    dp.resize(n , 0);
    return topdown(message, n - 1);
}