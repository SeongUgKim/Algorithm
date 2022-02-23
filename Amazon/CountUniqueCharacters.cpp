#include <string>
#include <cstring>
class Solution {
public:
    int uniqueLetterString(string s) {
        int sum = 0;
        int n = s.size();
        int cur = 0;
        int last[26];
        int prev[26];
        memset(last, -1, sizeof(last));
        memset(prev, -1, sizeof(prev));
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'A';
            cur += (i -last[c] - 1) - (last[c] - prev[c]) + 1;
            prev[c] = last[c];
            last[c] = i;
            sum += cur;
        }
        return sum;
    }
};
