#include <vector>
using namespace std;
int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int total = 0;
    for (int i = 0; i < n; ++i) 
        total += stones[i];
    int s2 = total / 2;
    int maxs = 0;
    vector<bool> dp(s2 + 1, false);
    dp[0] = true;
    for (int stone : stones) {
        for (int sum = s2; sum >= stone; --sum) {
            dp[sum] = dp[sum] || dp[sum - stone];
            if (dp[sum]) maxs = max(maxs, sum);
        }
    }
    return total - 2 * maxs;
}
