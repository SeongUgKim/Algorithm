#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i)
    {
        int key = target - nums[i];
        if (mp.count(key))
        {
            res.push_back(mp[key]);
            res.push_back(i);
            break;
        }
        mp[nums[i]] = i;
    }
    return res;
}
