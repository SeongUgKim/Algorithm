#include "stdc++.h"
#include <unordered_set>
using namespace std;

int solve(string s)
{
    if (s.length() < 2)
    {
        return s.length();
    }
    unordered_set<char> set;
    int start = 0;
    int end = 0;
    int length = 0;
    while (end < s.length())
    {
        if (!set.count(s[end]))
        {
            set.insert(s[end]);
            end++;
        }
        else
        {
            length = max(length, end - start);
            set.erase(s[start++]); // because move start position, then the number should be erased from the hash set.
        }
    }
    length = max(length, end - start);
    return length;
}

int main()
{
    string s = "dvdf";
    cout << solve(s) << endl;
    return 0;
}