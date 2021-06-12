#include <vector>
#include <unordered_map>
using namespace std;

bool solve(vector<int>& nums) {
    unordered_map<int ,int> mp;
    for (int a : nums)
    {
        mp[a]++;
    }
    for (auto m : mp)
    {
        if (m.first == m.second)
        {
            return true;
        }
    }
    return false;
}

