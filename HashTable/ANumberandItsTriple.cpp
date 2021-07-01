#include <vector>
#include <unordered_map>
using namespace std;
bool solve(vector<int>& nums) {
    if (nums.size() == 0) return false;
    unordered_map<int, int> mp;
    int count = 0;
    for (int a : nums) mp[a * 3]++;
    for (int a : nums) {
        if (a == 0) {
            count++;
            continue;
        }
        if (mp.find(a) != mp.end()) return true;
    }
    if (count > 1) return true; 
    return false;
}