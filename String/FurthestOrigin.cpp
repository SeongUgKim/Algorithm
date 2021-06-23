#include "stdc++.h"
using namespace std;

int solve(string s) {
    int l = 0;
    int r = 0;
    int q = 0;
    for (char c : s)
    {
        if (c == 'L')
        {
            l++;
        }
        else if (c == 'R')
        {
            r++;
        }
        else 
        {
            q++;
        }
    }
    int diff = 0;
    if (r > l)
    {
        diff = r - l;
    }
    else 
    {
        diff = l - r;
    }
    return diff + q;
}