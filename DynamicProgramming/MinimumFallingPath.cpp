#include <vector>
#include <climits>
using namespace std;

int solve(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int ret = INT_MAX;
	if (n == 1) {
		for (int i = 0; i < n; ++i) {
			ret = min(ret, matrix[0][i]);
		}
		return ret;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == 0) matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
			else if (j == n - 1) matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
			else matrix[i][j] += min({matrix[i - 1][j], matrix[i - 1][j + 1], matrix[i - 1][j - 1]});
			if (i == n - 1) ret = min(matrix[i][j], ret);
		}
	}
	return ret;
}
