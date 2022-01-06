#include <vector>
using namespace std;

int solve(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j == 0) matrix[i][j] = min(matrix[i - 1][j], matrix[i - 1][j + 1]) + matrix[i][j];
			else if (j == m - 1) matrix[i][j] = min(matrix[i - 1][j], matrix[i - 1][j - 1]) + matrix[i][j];
			else matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matirx[i - 1][j + 1])) + matrix[i][j];
		}
	}
	int ret = matrix[n - 1][0];
	for (int i = 1; i < m; ++i) 
		ret = min(ret, matrix[n - 1][i]);
	return ret;
}
