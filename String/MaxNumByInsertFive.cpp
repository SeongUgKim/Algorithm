#include <string>
using namespace std;
int solve(int n) {
    string s = to_string(n);
    string res = "";
    if (n >= 0)
    {
        int i = 0;
        for (; i < s.size(); ++i)
        {
            if (s[i] < '5')
            {
                res += '5';
                res += s[i];
                for (int j = i + 1; j < s.size(); ++j)
                {
                    res += s[j];
                }
                break;
            }
            res += s[i];
        }
        if (i == s.size())
        {
            res += '5';
        }
    }
    else
    {
        int i = 0;
        for (; i < s.size(); ++i)
        {
            if (s[i] > '5')
            {
                res += '5';
                res += s[i];
                for (int j = i + 1; j < s.size(); ++j)
                {
                    res += s[j];
                }
                break;
            }
            res += s[i];
        }
        if (i == s.size())
        {
            res += '5';
        }
    }
    int ret = stoi(res);
    return ret;
}