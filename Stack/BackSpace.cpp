#include "stdc++.h"
using namespace std;

string finalString(string s)
{
    string ret = "";
    int backspace = 0;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        if (s[i] == '#')
        {
            backspace++;
            continue;
        }
        if (backspace == 0)
        {
            ret += s[i];
            continue;
        }
        backspace--;
    }
    cout << ret << endl;
    return ret;
}

bool solve(string S, string T)
{
    /*stack<char> s1;
    stack<char> s2;
    for (char a : S)
    {
        if (a == '#')
        {
            if (!s1.empty())
            {
                s1.pop();
            }
            continue;
        }
        s1.push(a);
    }
    for (char b : T)
    {
        if (b == '#')
        {
            if (!s2.empty())
            {
                s2.pop();
            }
            continue;
        }
        s2.push(b);
    }
    if (s1.size() != s2.size())
    {
        return false;
    }
    while (!s1.empty())
    {
        if (s1.top() != s2.top())
        {
            return false;
        }
        s1.pop();
        s2.pop();
    }
    return true;*/
    string s = finalString(S);
    string t = finalString(T);
    return s == t;
}

int main()
{
    string S = "a##c";
    string T = "#a#c";
    cout << solve(S, T) << endl;
    return 0;
}