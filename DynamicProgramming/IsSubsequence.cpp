#include "stdc++.h"
using namespace std;

/*
bool solve(string s, string t, int m, int n)
{
    if (m == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (s[m - 1] == t[n - 1])
    {
        return solve(s, t, m - 1, n - 1);
    }
    return solve(s, t, m, n - 1);
}

bool isSubsequence(string s, string t)
{
    int m = s.size();
    int n = t.size();
    return solve(s, t, m, n);
}
*/
bool solve(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if(s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    if (i == m)
    {
        return true;
    }
    return false;
}
int main()
{
    string s = "abc";
    string t = "ahbgdc";
    cout << solve(s, t) << endl;
    return 0;
}