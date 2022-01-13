#include <unordered_map>
using namespace std;

int solve(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int a : nums) {
        mp[a]++;
    }
    int count = 0;
    for (auto m : mp) {
        if (m.second == 1) count++;
        if (m.second > 1) {
            for (int i = 1; i < m.second; ++i) {
                count += i;
            }
            count += m.second;
        }
    }
    return count;
}
