#include <string>
using namespace std;

string solve(string s) {
    string res;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] != s[i + 1])
        {
            res += s[i];
        }
    }
    if (s[n - 1] != res[res.size() - 1])
    {
        res += s[n - 1];
    }
    return res;
}