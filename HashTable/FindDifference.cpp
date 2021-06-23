#include "stdc++.h"
using namespace std;

char findTheDifference(string s, string t)
{
/*    char ret = '\0';
    if (s.length() == 0)
    {
        return t[0];
    }
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    for (char c : s)
    {
        map1[c]++;
    }
    for (char c : t)
    {
        map2[c]++;
    }
    for (char c : t)
    {
        if (map1[c] != map2[c])
        {
            ret = c;
        }
    }
    return ret;*/
/*    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != t[i])
        {
            return t[i];
        }
    }
    return t[t.length() - 1];
*/
    char x = 0;
    for (char ch : s)
    {
        x ^= ch;
    }
    for (char ch : t)
    {
        x ^= ch;
    }
    return x;
}

int main()
{
    string s = "ae";
    string t = "aae";
    cout << findTheDifference(s, t) << endl;
}