#include <string>
using namespace std;
int solve(string s) {
    int countx = 0;
    int county = 0;
    int n = s.size();
    if (n == 0) return 0;
    int dp[n] = {0};
    dp[0] = 0;
    if (s[0] == 'x') countx++;
    else county++;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'x') {
            dp[i] = min({++countx, county, dp[i - 1] + 1});
        }
        else {
            dp[i] = min({++county, countx, dp[i - 1]});
        }
    }
    return dp[n - 1];
}
