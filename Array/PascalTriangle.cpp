#include "stdc++.h"
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> a;
    for (int i = 0; i < numRows; ++i)
    {
        vector<int> v(i + 1, 1);
        for (int j = 1; j < i; ++j)
        {
            v[j] = a[i - 1][j] + a[i - 1][j - 1];
        }
        a.push_back(v);
    }
    return a;
}

int main()
{
    vector<vector<int>> a = generate(3);
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}