#include "stdc++.h"
using namespace std;

bool isPerfectSquare(int num)
{
    int lo = 1;
    int hi = num;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (mid * mid == num)
        {
            return true;
        }
        else if (mid * mid < num)
        {
            lo = mid + 1;
        }
        else 
        {
            hi = mid - 1;
        }
    }
    return false;

    int a = 1;
    while (num > 0)
    {
        num -= a;
        a += 2;
    }
    return num == 0;
}