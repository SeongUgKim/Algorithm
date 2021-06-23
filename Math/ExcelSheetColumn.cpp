#include "stdc++.h"
using namespace std;

int solve(string s)
{
    int n = s.size() - 1;
    int ret = 0;
    for (char c : s)
    {
        ret += (c - 'A'+ 1) * pow(26, n--);
    }
    return ret;
}

int main()
{
    string s = "ZY";
    cout << solve(s) << endl;
    return 0;
}