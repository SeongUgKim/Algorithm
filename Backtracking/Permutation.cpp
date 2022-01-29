#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int start, int end) {
        if (start == end) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i <= end; ++i) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1, end);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        dfs(nums, 0, nums.size() - 1);
        return res;
    }
};
