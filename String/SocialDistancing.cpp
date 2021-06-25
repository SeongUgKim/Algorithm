#include <string>
using namespace std;
bool solve(string s, int k) {
    int n = s.size();
    if (n == 1) return k == 1 ? true : false;
    int l;
    int r;
    int dis = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'x') continue;
        if (i == 0) {
            r = i + 1;
            while (r < n && s[r] != 'x') {
                r++;
            }
            dis = max(dis, abs(r - i));
        }
        else if (i == n - 1) {
            l = i - 1;
            while (l >= 0 && s[l] != 'x') {
                l--;
            }
            dis = max(dis, abs(l - i));
        }
        else {
            l = i - 1;
            r = i + 1;
            while (l >= 0 && s[l] != 'x') {
                l--;
            }
            while (r < n && s[r] != 'x') {
                r++;
            }
            dis = max(dis, min(abs(l - i), abs(r - i)));
        }
    }
    return dis >= k;
}