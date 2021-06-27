#include <vector>
#include <unordered_map>
using namespace std;
vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    int rank = 0;
    vector<int> copy(n);
    vector<int> res(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        copy[i] = nums[i];
    }
    sort(copy.begin(), copy.end());
    for (int i = n - 1; i >= 0; --i) {
        if (mp.find(copy[i]) == mp.end()) mp[copy[i]] = rank++;
    }
    for (int i = 0; i < n; ++i) {
        res[i] = mp[nums[i]];
    }
    return res;
}