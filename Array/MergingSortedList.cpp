#include "stdc++.h"
using namespace std;

vector<int> solve(vector<int>& a, vector<int>& b)
{
    vector<int> ret;
    int x = 0;
    int y = 0;
    while (x < a.size() && y < b.size())
    {
        ret.push_back(a[x] > b[y] ? b[y++] : a[x++]);
    }
    if (x == a.size())
    {
        while (y < b.size())
        {
            ret.push_back(b[y++]);
        }
        return ret;
    }
    while (x < a.size())
    {
        ret.push_back(a[x++]);
    }
    return ret;
}

int main()
{
    vector<int> a = {5, 10, 15};
    vector<int> b = {3, 8, 9};
    vector<int> ret = solve(a, b);
    for (auto a : ret)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}