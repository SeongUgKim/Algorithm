#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct comp {
        bool operator()(const string& s1, const string& s2) {
            return s1.size() < s2.size();
        }
    };
    
    bool wordBreak(string& word, unordered_set<string>& wordDict) {
        int n = word.size();
        vector<bool> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            string sub;
            for (int j = i; j < n; ++j) {
                if (dp[i] = wordDict.count(sub += word[j]) && dp[j + 1]) break;
            }
        }
        return dp[0];
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;
        vector<string> ans;
        sort(words.begin(), words.end(), comp());
        for (auto& word : words) {
            int n = word.size();
            if (n == 0) continue;
            if (wordBreak(word, st)) ans.push_back(word);
            st.insert(word);
        }
        return ans;
    }
};
