#include <string>
using namespace std;

int countBinarySubstrings(string s) {
    int prev = 0; 
    int count = 0;
    int cur = 1;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            count += min(prev, cur);
            prev = cur;
            cur = 1;
        } else {
            cur++;
        }
    }
    return count + min(prev, cur);
}
