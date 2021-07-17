#include <vector>
#include <unordered_map>
using namespace std;
vector<int> solve(vector<int>& nums) {
    unordered_map<int, int> mp;
    vector<int> res;
    for (int a : nums) {
        mp[a]++;
    }
    int n = nums.size();
    for (int i = n - 1; i >= 0; --i) {
        if (mp[nums[i]] > 1) {
            mp[nums[i]] = 0;
            continue;
        }
        res.push_back(nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}