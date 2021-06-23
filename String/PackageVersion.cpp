#include "stdc++.h"
using namespace std;

bool solve(string older, string newer)
{
    int count1 = 0;
    int count2 = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    for (; k < 2; ++k)
    {
        while (older[i] != '.')
        {
            count1++;
            i++;
        }
        while (newer[j] != '.')
        {
            count2++;
            j++;
        }
        if (count1 > count2)
        {
            return false;
        }
        if (count2 > count1)
        {
            return true;
        }
        i = i - count1;
        j = j - count2;
        while (older[i] != '.')
        {
            if (older[i] > newer[j])
            {
                return false;
            }
            if (older[i] < newer[j])
            {
                return true;
            }
            i++;
            j++;
        }
        i++;
        j++;
        count1 = 0;
        count2 = 0;
    }
    for (; i < older.size(); ++i)
    {
        count1++;
    }
    for (; j < newer.size(); ++j)
    {
        count2++;
    }
    if (count1 > count2)
    {
        return false;
    }
    if (count2 > count1)
    {
        return true;
    }
    i = i - count1;
    j = j - count2;
    while (i < older.size())
    {
        if (older[i] > newer[j])
            {
                return false;
            }
            if (older[i] < newer[j])
            {
                return true;
            }
            i++;
            j++;
    }
    return false;
}


int main()
{   
    string older = "0.0.100";
    string newer = "1.0.0";
    cout << solve(older, newer) << endl;
    return 0;
}