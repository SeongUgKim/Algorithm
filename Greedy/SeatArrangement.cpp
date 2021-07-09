#include <vector>
using namespace std;
bool solve(int n, vector<int>& seats) {
    int m = seats.size();
    if (n == 0) return true;
    if (m == 0) return false;
    int first_count = 0;
    int count = 0;
    int res = 0;
    int i = 0;
    while (seats[i] != 1 && i < m) {
        first_count++;
        i++;
    }
    if (i == m) {
        res = (first_count + 1) / 2;
        return res >= n;
    }
    res += first_count / 2;
    for (; i < m; ++i) {
        if (seats[i] == 1) {
            res += (count - 1) / 2;
            count = 0;
            continue;
        }
        count++;
    }
    if (count != 0) res += count / 2;
    return res >= n;
}