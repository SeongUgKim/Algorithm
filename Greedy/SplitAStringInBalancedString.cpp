#include <string>
using namespace std;
int balancedStringSplit(string s) {
    int l = 0;
    int r = 0;
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'L')
        {
            l++;
        }
        if (s[i] == 'R')
        {
            r++;
        }
        if (l == r)
        {
            count++;
            l = 0;
            r = 0;
        }
    }
    return count;
}
