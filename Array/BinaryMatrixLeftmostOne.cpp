#include <vector>
#include <climits>
using namespace std;
int solve(vector<vector<int>>& matrix) {
    int min_val = INT_MAX;
    int n = matrix.size();
    if (n == 0) return -1;
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                min_val = min(min_val, j);
            }
        }
    }
    if (min_val == INT_MAX) return -1;
    return min_val;
}