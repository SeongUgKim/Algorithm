#include <vector>
using namespace std;
int solve(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();
    int l = min(n, m);
    sort(nums.begin(), nums.end());
    sort(multipliers.begin(), multipliers.end());
    int bn = 0;
    int bm = 0;
    int en = n - 1;
    int em = m - 1;
    int sum = 0;
    for (int i = 0; i < l; ++i) {
        int x = nums[bn] * multipliers[bm];
        int y = nums[en] * multipliers[em];
        if (x > y) {
            sum += x;
            bn++;
            bm++;
        }
        else {
            sum += y;
            en--;
            em--;
        }
    }
    return sum;
}