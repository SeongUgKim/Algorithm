#include <string>
using namespace std;
class Solution {
public:
    int count(string& a, string& b) {
        int ans = INT_MAX;
        for (char c = 'a'; c < 'z'; ++c) {
            int cnt = 0;
            for (auto x : a) cnt += x > c;
            for (auto y : b) cnt += y <= c;
            ans = min(cnt, ans);
        }
        return ans;
    }
    int minCharacters(string a, string b) {
        int x = count(a, b);
        int y = count(b, a);
        int all = INT_MAX;
        for (char c = 'a'; c <= 'z'; ++c) {
            int cnt = 0;
            for (auto d : a) cnt += d != c;
            for (auto d : b) cnt += d != c;
            all = min(cnt, all);
        }
        return min({all, x, y});
    }
};

class Solution {
public:
    int minCharacters(string a, string b) {
        // calculate the operations for each condition and return the min operations among the conditions
        
        int m = a.size();
        int n = b.size();
        
        // calculate the freq of every character in a and b
        int freq1[26];
        int freq2[26];
        memset(freq1, 0, sizeof(freq1));
        memset(freq2, 0, sizeof(freq2));
        
        for (int i = 0; i < a.size(); ++i) {
            freq1[a[i] - 'a']++;
        }
        
        for (int i = 0; i < b.size(); ++i) {
            freq2[b[i] - 'a']++;
        }
        
        int res = INT_MAX;
        
        // for every character in alphabets get the number of operations to satisfy each condition
        for (int i = 0; i < 26; ++i) {
            // condition 3 change all the characters i char in alphabets
            // the total characters in both the strings which are different should be changed.
            res = min(res, m + n - freq1[i] - freq2[i]);
            if (i > 0) {
                freq1[i] += freq1[i - 1];
                freq2[i] += freq2[i - 1];
                // conditino 1
                // change all char in string a to strictly less than curr char i
                // change all char in string b to strictly greather than or equal curr char i
                // change all the char greater than curr i in a  -> m - freq[i - 1]
                res = min(res, m - freq1[i - 1] + freq2[i - 1]);
                // condition 2
                // change all the char in b strictly less than the curr character
                // change all char in a greater than or equal to curr char i
                res = min(res, n - freq2[i - 1] + freq1[i - 1]);
           }
        }
        return res;
    }
};
