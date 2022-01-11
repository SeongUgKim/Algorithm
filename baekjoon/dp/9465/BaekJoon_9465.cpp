#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int T;
	int N;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		int dp[2][100001] = {0, };
		int a[2][100001] = {0, };
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> a[i][j];
			}
		}
		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1];
		for (int i = 2; i <= N; ++i) {
			dp[0][i] = a[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = a[1][i] + max(dp[0][i - 1], dp[0][i - 2]);	
		}
		cout << max(dp[0][N], dp[1][N]) << endl;
	}	
	return 0;
}
