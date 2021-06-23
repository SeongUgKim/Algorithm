#include "stdc++.h"
using namespace std;

bool detectCapitalUse(string word)
{
    vector<int> array;
    for (char c : word)
    {
        if (c >= 65 && c <= 90)
        {
            array.push_back(1);
            continue;
        }
        array.push_back(0);
    }
    if (array[0] != 1)
    {
        for (int i = 1; i < array.size(); ++i)
        {
            if (array[i] == 1)
            {
                return false;
            }
        }
        return true;
    }
    bool allUpper = true;
    bool allLower = true;
    for (int i = 1; i < array.size(); ++i)
    {
        if (array[i] == 1)
        {
            allLower = false;
        }
    }
    for (int i = 1; i < array.size(); ++i)
    {
        if (array[i] == 0)
        {
            allUpper = false;
        }
    }
    if (allLower == true || allUpper == true)
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "FLaG";
    cout << detectCapitalUse(s) << endl;
}