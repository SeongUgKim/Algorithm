#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

    bool canBreak(int start, string& s, unordered_set<string>& wordDict, vector<int>& mem) {
        int n = s.size();
        if (n == start) return 1;
        if (mem[start] != -1) return mem[start];
        string sub;
        for (int i = start + 1; i <= n; ++i) {
            if (wordDict.count(s.substr(start, i - start))  && canBreak(i, s, wordDict, mem)) return mem[start] = 1;
        }
        return mem[start] = 0;
    }
    bool wordBreakRecursive(string s, vector<string>& wordDict) {
        vector<int> mem(s.size(), -1);
        unordered_set<string> dict;
        for (auto& str : wordDict) {
            dict.insert(str);
        }
        return canBreak(0, s, dict, mem);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && word_set.count(s.substr(j, i - j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
