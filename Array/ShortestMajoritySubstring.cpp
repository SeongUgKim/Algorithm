#include <string>
#include <unordered_set>
using namespace std;
int solve(string s) {
    int n = s.size();
    unordered_set<int> st;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < i + 3; ++j) {
            if (j == n) break;
            if (s[i] == s[j]) st.insert(j - i + 1);
        }
    }
    if (st.count(2)) return 2;
    if (st.count(3)) return 3;
    return -1;
}
