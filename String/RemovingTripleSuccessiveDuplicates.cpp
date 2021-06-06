#include <string>
using namespace std;
int solve(string s) {
    int count = 1;
    int res = 0;
    int add;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            continue;
        }
        add = count / 3;
        res += add;
        count = 1;
    }
    add = count / 3;
    res += add;
    return res;
}