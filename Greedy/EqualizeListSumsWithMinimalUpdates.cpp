#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& a, vector<int>& b) {
    if (max(a.size(), b.size()) > 6 * min(a.size(), b.size())) return -1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sum1 = 0, sum2 = 0;
    for (int i : a) sum1 += i;
    for (int i : b) sum2 += i;
    if (sum1 > sum2) return solve(b, a);
    reverse(b.begin(), b.end());
    int i = 0;
    int j = 0;
    int res = 0;
    int diff = sum2 - sum1;
    while (diff > 0) {
        res++;
        if (i < a.size() && j < b.size()) {
            int first = 6 - a[i];
            int second = b[j] - 1;
            if (first > second) {
                diff -= first;
                i++;
            }
            else {
                diff -= second;
                j++;
            }
        }
        else {
            if (i < a.size()) {
                diff -= (6 - a[i++]);
            } else if (j < b.size()) {
                diff -= (b[j++] - 1);
            }
        }
    }
    return res;
}