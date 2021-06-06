#include <vector>
using namespace std;
vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int index = abs(nums[i]) - 1;
        nums[index] = nums[index] < 0 ? nums[index] : -nums[index];
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] > 0)
        {
            nums[count++] = i + 1;
        }
    }
    nums.resize(count);
    return nums;
}

