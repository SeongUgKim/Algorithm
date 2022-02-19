#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> dp(n);
        vector<int> p(n + 1);
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] + (s[i] == '1' ? 1 : 0);
        }
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') dp[i] = dp[i - 1];
            else dp[i] = min(p[i + 1], dp[i - 1] + 1);
        }
        return dp[n - 1];
    }
    int upgradeVersion(string s) {
        int flip, count = 0;
        for (auto c : s) {
            if (c == '1') count++;
            else flip++;
            flip = min(flip, count);
        }
        return flip;
    }
};
