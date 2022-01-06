// topdown
#include <vector>
#include <cstring>
using namespace std;

int cache[600][101][101];
int topdown(vector<string>& strs, int index, int m, int n) {
    int one = 0;
    int zero = 0;
    if (index == strs.size()) return 0;
    if (m == 0 && n == 0) return 0;
    int& res = cache[index][m][n];
    if (res != -1) return res;
    for (int i = 0; i < strs[index].size(); ++i) {
        if (strs[index][i] == '0') zero++;
        if (strs[index][i] == '1') one++;
    }
    if (m == 0) {
        if (one > n || zero > 0) return res = topdown(strs, index + 1, m, n);
        return res = max(topdown(strs, index + 1, m, n - one) + 1, topdown(strs, index + 1, m, n));
    }
    if (n == 0) {
        if (zero > m || one > 0) return res = topdown(strs, index + 1, m, n);
        return res= max(topdown(strs, index + 1, m - zero, n) + 1, topdown(strs, index + 1, m, n));
    }
    if (one > n || zero > m) return res = topdown(strs, index + 1, m, n);
    return res = max(topdown(strs, index + 1, m - zero, n - one) + 1, topdown(strs, index + 1, m, n));
}
int findMaxForm(vector<string>& strs, int m, int n) {
    memset(cache, -1, sizeof(cache));
    return topdown(strs, 0, m, n);
}

// bottom up
int findMaxForm(vector<string>& strs, int m, int n) {
    int cache[101][101] = {0, };
    int one;
    int zero;
    for (string s : strs) {
        int zero = count(s.begin(), s.end(), '0');
        int one = count(s.begin(), s.end(), '1');
        for (int i = m; i >= zero; --i)
            for (int j = n; j >= one; --j)
                cache[i][j] = max(cache[i][j], cache[i - zero][j - one] + 1);
    }
    return cache[m][n];
    
}
