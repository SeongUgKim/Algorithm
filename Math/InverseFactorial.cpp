#include "stdc++.h"
using namespace std;

int solve(int a) {
    int n = 1;
    int remain = 0;
    while (a > 0)
    {
        remain = a % n;
        if (remain != 0)
        {
            return -1;
        }
        a /= n;
        if (a == 1)
        {
            return n;
        }
        n++;
    }
    return -1;
}