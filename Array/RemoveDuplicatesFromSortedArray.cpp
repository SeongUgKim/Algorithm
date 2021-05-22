#include <vector>
using namespace std;

int solve(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0) 
    {
        return 0;
    }
    int i = 0;
    for (int j = 0; j < n; ++j) 
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}