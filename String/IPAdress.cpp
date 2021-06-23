#include "stdc++.h"
using namespace std;

bool solve(string s)
{
    int num = 0;
    string a = "";
    int dotCount = 0;
    if (s[0] < '0' || s[0] > '9')
    {
        return false;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '.')
        {
            num = 0;
            a = "";
            dotCount++;
            if (s[i + 1] < '0' || s[i + 1] >'9')
            {
                return false;
            }
            continue;
        }
        a += s[i];
        if (s[i + 1] == '.' || i + 1 == s.size())
        {
            if (a.size() > 1)
            {
                if (a[0] == '0' && a[1] == '0')
                {
                    return false;
                }
            }
            int k = a.size() - 1;
            for (int j = 0; j < a.size(); ++j)
            {
                num += (a[j] - '0') * pow(10, k--);
            }
            if (num < 0 || num > 255)
            {
                return false;
            }
        }
    }
    if (dotCount != 3)
    {
        return false;
    }
    return true;
    
}

int main()
{
    string s = "0.0.0.0";
    cout << solve(s) << endl;
}
