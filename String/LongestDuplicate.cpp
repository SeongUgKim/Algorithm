#include "stdc++.h"
using namespace std;

int solve(string s)
{
    if (s.size() <= 1)
    {
        return s.size();
    }
    int count = 1;
    int ret = 0;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            continue;
        }
        ret = max(ret, count);
        count = 1;
    }
    ret = max(ret, count);
    return ret;

}

int main()
{
    string s = "aaabbbb";
    cout << solve(s) << endl;
    return 0;
}