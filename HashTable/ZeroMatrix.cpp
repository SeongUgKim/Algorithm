#include "stdc++.h"
#include <unordered_set>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& matrix) {
    unordered_set<int> st1;
    unordered_set<int> st2;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                st1.insert(i);
                st2.insert(j);
            }
        }
    }

    for (int n : st1)
    {
        for (int i = 0; i < matrix[0].size(); ++i)
        {
            matrix[n][i] = 0;
        }
    }

    for (int n : st2)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            matrix[i][n] = 0;
        }
    }
    return matrix;
}