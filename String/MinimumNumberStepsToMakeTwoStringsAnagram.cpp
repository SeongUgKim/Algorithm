#include <unordered_map>
#include <cmath>
using namespace std;
int minSteps(string s, string t) {
    unordered_map<char, int> mp;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        mp[s[i]]++;
        mp[t[i]]--;
    }
    int count = 0;
    for (auto m : mp) {
        count += abs(m.second);
    }
    return count / 2;
}
