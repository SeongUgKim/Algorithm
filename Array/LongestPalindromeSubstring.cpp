#include "stdc++.h"
using namespace std;
    int subStrLength(string s, int l, int r)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }
    
    string longestPalindrome(string s)
    {
        if (s.size() == 0)
        {
            return "";
        }
        int start = 0;
        int maxLength = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int len1 = subStrLength(s, i, i);
            int len2 = subStrLength(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLength)
            {
                start = i - (len - 1) / 2;
                maxLength = len;
            }
        }
        return s.substr(start, maxLength);
    }