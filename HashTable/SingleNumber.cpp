#include <vector>
#include <unordered_map>
using namespace std;
int solve(vector<int>& nums)
{
    int res;
    unordered_map<int, int> mp;
    for (int a : nums) 
    {
        mp[a]++;
    }
    for (auto m : mp)
    {
        if (m.second == 1)
        {
            res = m.first;
        }
    }
    return res;
}

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int a : nums)
    {
        res ^= a;
    }
    return res;
}