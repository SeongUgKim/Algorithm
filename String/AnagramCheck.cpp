#include "stdc++.h"
using namespace std;

bool solve(string s0, string s1)
{
    /*sort(s0.begin(), s0.end());
    sort(s1.begin(), s1.end());
    return s0 == s1;*/
    if (s0.size() != s1.size())
    {
        return false;
    }
    unordered_map<char, int> mp;
    for (char c : s0)
    {
        mp[c]++;
    }
    for (char c : s1)
    {
        mp[c]--;
        if (mp[c] == 0)
        {
            mp.erase(c);
        }
    }
    return mp.size() == 0;

}

int main()
{
    string s0 = "abc";
    string s1 = "cab";
    cout << solve(s0, s1) << endl;
    return 0;
}