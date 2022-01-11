#include <iostream>
using namespace std;

int main() 
{
	int N;
	cin >> N;
	long long cache[91][2] = {0, };
	cache[1][0] = 0;
	cache[1][1] = 1;
	for (int i = 2; i <= N; ++i) {
		cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
		cache[i][1] = cache[i - 1][0];
	}
	cout << cache[N][0] + cache[N][1] << endl;
	return 0;
}
