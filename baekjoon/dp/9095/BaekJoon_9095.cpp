#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	vector<int> arr;
	cin >> N;
	int dp[12];
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		memset(dp, 0, sizeof(dp));
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int j = 4; j <= temp; ++j) {
			dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
		}
		arr.push_back(dp[temp]);
	}
	for (int i = 0; i < arr.size(); ++i) cout << arr[i] << endl;
	return 0;
}
