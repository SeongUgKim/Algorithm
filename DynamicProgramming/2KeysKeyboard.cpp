#include <vector>
using namespace std;
// topdown
int dp[1001][1001];
int topdown(int n, int length, int copy) {
    if (length == n) return 0;
    if (length > n) return 1001;
    if (dp[length][copy] != -1) return dp[length][copy];
    if (copy == 0) return dp[length][copy] = topdown(n, length, length) + 1;
    if (length == copy) return dp[length][copy] = topdown(n, length + copy, copy) + 1;
    return dp[length][copy] = min(topdown(n, length + copy, copy), topdown(n, length, length)) + 1;
}
int minSteps(int n) {
    memset(dp, -1, sizeof(dp));
    return topdown(n, 1, 0);
}