#include <vector>
using namespace std;
int solve(vector<int>& nums, int k) {
    int sum = 0;
    int res = -1;
    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        if (sum <= k)
        {
            res = i;
        }
    }
    return res;
}