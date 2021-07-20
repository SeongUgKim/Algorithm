#include <unordered_map>
#include <vector>
using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y , x % y);
}
bool solve(vector<int>& nums) {
    if (nums.size() <= 1) return false;
    unordered_map<int, int> mp;
    for (int num : nums) {
        mp[num]++;
    }
    int min_val = INT_MAX;
    int check = mp.begin()->second;
    for (auto m : mp) {
        check = gcd(check, m.second);
    }
    return check >= 2;
}