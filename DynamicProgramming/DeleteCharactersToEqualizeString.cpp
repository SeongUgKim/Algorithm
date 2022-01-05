#include <string> 
using namespace std;

int solve(string a, string b) {
	int n = a.size();
	int m = b.size();
	if (n == 0) return m;
	if (m == 0) return n;
	int cache[1001][1001];
	for (int i = 0; i <= n; ++i) cache[i][0] = i;
	for (int i = 1; i <= m; ++i) cache[0][i] = i;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			cache[i][j] = a[i - 1] == b[j - 1] ? cache[i - 1][j - 1] : min(cache[i - 1][j], cache[i][j - 1])  + 1;
	return cache[n][m];
}
