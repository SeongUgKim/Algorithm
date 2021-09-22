#include <unordered_map>
#include <string>
using namespace std;
int longestPalindrome(string s) {
    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    bool flag = false;
    int count = 0;
    for (auto m : mp) {
        if (m.second % 2 == 1) {
            count += (m.second - 1);
            flag = true;
        }
        else count += m.second;
    }
    if (flag) count++;
    return count;
}