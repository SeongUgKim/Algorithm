#include "stdc++.h"
using namespace std;

int getNum(int n)
{
    int ret = 0;
    while (n > 0)
    {
        ret += (n % 10) * (n % 10);
        n /= 10;
    }
    return ret;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = getNum(n);

    while (slow != fast) 
    {
        slow = getNum(slow);
        fast = getNum(getNum(fast));
    }

    if (slow == 1)
    {
        return true;
    }
    return false;
}