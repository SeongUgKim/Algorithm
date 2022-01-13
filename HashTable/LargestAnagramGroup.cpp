#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int solve(vector<string>& words) {
    unordered_map<string, int> mp;
    int max_size = 0;
    for (string s : words) {
        sort(s.begin(), s.end());
        max_size = max(max_size, ++mp[s]);
    }
    return max_size;

}
