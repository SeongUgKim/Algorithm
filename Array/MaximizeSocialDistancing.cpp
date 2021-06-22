#include <vector>
#include <limits>
using namespace std;
int solve(vector<int>& seats) {
    int n = seats.size();
    int mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (seats[i] == 1) continue;
        int j = 1;
        if (i == 0) {
            while (i + j <= n - 1) {
                if (seats[i + j] == 0) j++;
                else break;
            }
        }
        else if (i == n - 1) {
            while (i - j >= 0) {
                if (seats[i - j] == 0) j++;
                else break;
            }
        }
        else {
            while (i - j >= 0 && i + j <= n - 1) {
                if (seats[i + j] == 0 && seats[i - j] == 0) j++;
                else break;
            }
        }
        mx = max(j, mx);
    }
    return mx;
}
