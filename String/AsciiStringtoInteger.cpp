#include "stdc++.h"
using namespace std;
int solve(string s)
{
    int res = 0;
    string cur = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (!isdigit(s[i]))
        {
            if (cur.size() == 0) 
            {
                continue;
            }
            res += stoi(cur);
            cur = "";
        }
        else 
        {
            cur += s[i];
        }
    }
    if (cur.size() > 0)
    {
        res += stoi(cur);
    }
    return res;
}