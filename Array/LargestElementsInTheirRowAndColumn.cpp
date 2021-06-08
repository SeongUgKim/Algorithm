#include <vector>
using namespace std;
int solve(vector<vector<int>>& matrix) 
{
    vector<int> row(matrix.size(), 0);
    vector<int> col(matrix[0].size(), 0);
    int count = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 1)
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 1 && row[i] == 1 && col[j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

