#include "stdc++.h"
using namespace std;

int sqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    int low = 1;
    int high = x;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return low - 1;
}