#include <vector>
using namespace std;
int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int r[n];
    int l[n];
    memset(r, 0, sizeof(r));
    memset(l, 0, sizeof(l));
    r[n - 1] = nums[n - 1];
    r[n - 2] = nums[n - 2];
    l[0] = nums[0];
    l[1] = nums[1];
    for (int i = 2; i < n; ++i) {
        l[i] = nums[i] + l[i - 2];
    }
    for (int i = n - 3; i >= 0; --i) {
        r[i] = nums[i] + r[i + 2];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int l1 = i - 2 >= 0 ? l[i - 2] :  0;
        int r1 = i + 1 < n ? r[i + 1] : 0;
        int l2 = i - 1 >= 0 ? l[i - 1] : 0;
        int r2 = i + 2 < n ? r[i + 2] : 0;
        if (l1 + r1 == l2 + r2) count++;
    }
    return count;
}