#include "stdc++.h"
using namespace std;

int firstUniqChar(string s)
{
    /*unordered_map<char, int> map;
    for (int i = 0; i < (int)s.length(); ++i)
    {
        map[s[i]] = map[s[i]] + 1;
    }
    int i = 0;
    for (; i < (int)s.length(); ++i)
    {
        if (map[s[i]] == 1) 
        {
            break;
        }
    }
    if (i < (int)s.length())
    {
        return i;
    }
    return -1;*/
    int alphabet[26] = {0, };
    for (char c : s)
    {
        alphabet[c - 'a']++;
    }
    int i = 0;
    for (; i < s.length(); ++i)
    {
        if (alphabet[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string s = "loveleetcode";
    cout << firstUniqChar(s) << endl;
    return 0;
}