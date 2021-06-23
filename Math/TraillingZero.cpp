#include "stdc++.h"
using namespace std;

int solve(int n)
{
    int ret = 0;
    while (n > 0)
    {
        ret += n / 5;
        n /= 5;
    }
    return ret;
}

int main()
{
    cout << solve(100) << endl;
    return 0;
}