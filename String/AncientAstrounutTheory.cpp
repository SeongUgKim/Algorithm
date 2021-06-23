#include "stdc++.h"
using namespace std;

bool solve(string dictionary, string s)
{
    if (dictionary.size() == 0)
    {
        return true;
    }
    unordered_map<char, int> mp;
    for (int i = 0; i < dictionary.size(); ++i)
    {
        mp[dictionary[i]] = i;
    }
    vector<int> v;
    for (char c : s)
    {
        if (mp.count(c))
        {
            v.push_back(c);
        }
    }
    if (v.size() == 0)
    {
        return true;
    }
    cout << endl;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (mp[v[i]] > mp[v[i + 1]] )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string dictionary = "acb";
    string s = "aaaacccbc";

    cout << solve(dictionary, s) << endl;
    return 0;
}