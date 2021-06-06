#include <vector>
#include <unordered_map>
using namespace std;
int solve(vector<int>& nums) {
    unordered_map<int, int> mp;
    int count = 0;
    for (int a : nums)
    {
        mp[a]++;
    }
    for (int a : nums)
    {
        if (mp.find(a + 1) != mp.end())
        {
            count++;
        }
    }
    return count;
}