#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> res;
    int matrix[rows][columns];
    int temp[rows][columns];
    int k = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = k;
            temp[i][j] = k;
            k++;
        }
    }
    int n = queries.size();
    for (int i = 0; i < n; ++i)
    {
        int y1 = queries[i][0] - 1;
        int y2 = queries[i][2] - 1;
        int x1 = queries[i][1] - 1;
        int x2 = queries[i][3] - 1;
        int minValue = INT_MAX;
        for (int j = x1 + 1; j <= x2; ++j)
        {
            matrix[y1][j] = temp[y1][j - 1];
            minValue = min(minValue, matrix[y1][j]);
        }
        for (int j = y1 + 1; j <= y2; ++j)
        {
            matrix[j][x2] = temp[j - 1][x2];
            minValue = min(minValue, matrix[j][x2]);
        }
        for (int j = x1; j < x2; ++j)
        {
            matrix[y2][j] = temp[y2][j + 1];
            minValue = min(minValue, matrix[y2][j]);
        }
        for (int j = y1; j < y2; ++j)
        {
            matrix[j][x1] = temp[j + 1][x1];
            minValue = min(minValue, matrix[j][x1]);
        }
        res.push_back(minValue);
        for (int j = y1; j <= y2; ++j)
        {
            for (int k = x1; k <= x2; ++k)
            {
                temp[j][k] = matrix[j][k];
            }
        }
    }
    return res;
}