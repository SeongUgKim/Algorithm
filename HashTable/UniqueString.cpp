#include "stdc++.h"
using namespace std;

bool solve(string s)
{
/*    if (s.size() <= 1) //Hashmap
    {
        return true;
    }
    unordered_map<char, int> map;
    for (char  c : s)
    {
        map[c]++;
    }
    for (char c : s)
    {
        if (map[c] != 1)
        {
            return false;
        }
    }
    return true;*/
    bool a[26] = {false}; //boolean array
    for (char c : s)
    {
        if (a[c - 'a'] == true)
        {
            return false;
        }
        a[c - 'a'] = true;
    }
    return true;
}

int main()
{
    string s =  "abcde";
    cout << solve(s) << endl;
    return 0;
}