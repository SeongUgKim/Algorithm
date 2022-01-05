#include <vector>
using namespace std;

int solve(vector<vector<int>>& matrix) {
	int cache[100][100];
	int n = matrix.size();
	int m = matrix[0].size();
	cache[0][0] = matrix[0][0];
	for (int i = 1; i < n ;++i) {
		cache[i][0] = matrix[i][0] + cache[i - 1][0];
	}
	for (int i = 1; i < m; ++i) {
		cache[0][i] = matrix[0][i] + cache[0][i - 1];
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			cache[i][j] = matrix[i][j] + max(cache[i - 1][j], cache[i][j - 1]);
		}
	}
	return cache[n - 1][m - 1];
}
