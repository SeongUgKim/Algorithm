#include "stdc++.h"
using namespace std;

vector<int> solve(int n)
{
    vector<int> ret;
    if (n == 0)
    {
        ret.push_back(1);
        return ret;
    }
    ret.resize(n + 1);
    ret[0] = 1;
    ret[ret.size() - 1] = 1;
    vector<int> temp = solve(n - 1);
    for (int i = 1; i < ret.size() - 1; ++i)
    {
        ret[i] = temp[i - 1] + temp[i];
    }
    return ret;
}

int main()
{
    vector<int> ret = solve(2);
    for (auto a : ret)
    {
        cout << a <<  " ";
    }
    cout << endl;
    return 0;

}