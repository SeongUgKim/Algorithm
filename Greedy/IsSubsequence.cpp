#include <string>
using namespace std;
bool isSubsequence(string s, string t) {
    int m = s.size();
    int n = t.size();
    if (m == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (s == t)
    {
        return true;
    }
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (s[i] == t[j])
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