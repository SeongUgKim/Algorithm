#include "stdc++.h"
using namespace std;

int longestPalindrome(string s)
{
    unordered_set<char> set;
    for (char  ch : s)
    {
        if (set.count(ch))
        {
            set.erase(ch);
        }
        else 
        {
            set.insert(ch);
        }
    }
    if (set.size() <= 1)
    {
        return s.length();
    }
    return s.length() - set.size() + 1;
}

int main()
{
    string s = "abcbe";
    cout << longestPalindrome(s) << endl;
}