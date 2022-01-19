#include <string>
#include <memory>
using namespace std;
string longestPalindrome(string s) {
    int n = s.size();
    int dp[1001][1001];
    memset(dp, 0, sizeof(dp));
    string ans = "";
    ans = s[0];
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                if (j - i == 1 || dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    if (j - i + 1 > ans.size()) ans = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return ans;
}
