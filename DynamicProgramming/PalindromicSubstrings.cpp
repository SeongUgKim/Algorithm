#include <string>
#include <memory>
using namespace std;
// bottom-up
// dp[i][j] = the substring strart from i to j is palindromic or not
int countSubstringsDp(string s) {
    int ans = 0;
    int n = s.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        ans++;
        if (i != n - 1 && s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            ans++;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 2; j < n; ++j) {
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans++;
            }
        }
    }
    return ans;
}

// expand from center
int countSubstrings(string s) {
    if (s.size() == 0) return 0;
    int res = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        res += count(i, i, s);
        res += count(i, i + 1, s);
    }
    return res;
}

int count(int start, int end, string& s) {
    int res = 0;
    while (start >= 0 && end < s.size() && s[start--] == s[end++])
        res++;
    return res;
}