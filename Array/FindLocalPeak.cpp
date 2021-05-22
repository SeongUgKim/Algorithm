#include <vector>
using namespace std;

vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    if (n <= 1)
    {
        return res;
    }
    for (int i = 0; i < n; ++i)
    {
        if ((i > 0 ? nums[i] > nums[i - 1] : true) && (i < n - 1 ? nums[i] > nums[i + 1] : true))
        {
            res.push_back(i);
        }
    }
    return res;
}