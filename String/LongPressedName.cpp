#include "stdc++.h"
using namespace std;

bool solve(string name, string typed)
{
    int i = 0;
    int j = 0;
    if (name[i++] != typed[j++])
    {
        return false;
    }
    while (i < name.length() && j < typed.length())
    {
        if (name[i] == typed[j])
        {
            i++;
            j++;
            continue;
        }
        if (typed[j] == typed[j - 1])
        {
            j++;
            continue;
        }
        return false;
    }
    while (j < typed.length())
    {
        if (typed[j] != typed[j - 1])
        {
            break;
        }
        j++;
    }
    if (i == name.length() && j == typed.length())
    {
        return true;
    }
    return false;

}

int main()
{
    string name = "vtkgn";
    string typed = "vttkgnn";
    cout << solve(name, typed) << endl;
    return 0;
}