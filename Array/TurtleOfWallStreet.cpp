#include <vector>
using namespace std;
int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
    {       
        return 0;
    }
    int profit = 0;
    int cur_max = nums[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        cur_max = max(nums[i], cur_max);
        int diff = cur_max - nums[i];
        profit += (diff > 0 ? diff : 0);
    }
    return profit;
}