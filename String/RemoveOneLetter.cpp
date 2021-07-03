#include <string>
using namespace std;
bool solve(string s0, string s1) {
    int m = s0.size();
    int n = s1.size();
    if (m == n) return false;
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
        if (count > 1) return false;
        if (s0[i] != s1[j]) {
            i++;
            count++;
            continue;
        }
        i++;
        j++;
    }
    if (j != n) return false;
    if (i == m && j == n) {
        if (count == 1) return true;
        return false;
    }
    if (i != m && j == n) {
        if (m - i == 1) return true;
        return false;
    }
    return false;
}