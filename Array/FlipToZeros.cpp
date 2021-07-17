#include <vector>
using namespace std;
int solve(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    int now = 1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == now) {
            count++;
            if (now == 1) now = 0;
            else now = 1;
        }
    }
    return count;
}