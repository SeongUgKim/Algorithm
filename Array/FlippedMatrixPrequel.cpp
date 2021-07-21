#include <vector>
using namespace std;
int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int totalOnes = 0;
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            totalOnes += (matrix[i][j] == 1);
            rows[i] += (matrix[i][j] == 0);
            cols[j] += (matrix[i][j] == 0);
        }
    }
    int res = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res = max(res, 2 * rows[i] + 2 * cols[j] + (matrix[i][j] == 0 ? -2 : 2));
        }
    }
    return res + totalOnes - n - m;

} 