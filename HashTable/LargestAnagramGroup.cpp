#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int solve(vector<string>& words) {
    unordered_map<string, int> mp;
    for (string s : words) {
        sort(s.begin(), s.end());
        mp[s]++;
    }
    int max_size = 0;
    for (auto m : mp) {
        max_size = max(m.second, max_size);
    }
    return max_size;

}
