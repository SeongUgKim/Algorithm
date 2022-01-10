#include <iostream>
using namespace std;

int main()
{
	int cache[1001] = {0, };
	int n;
	cin >> n;
	cache[1] = 1;
	cache[2] = 2;
	for (int i = 3; i <= n; ++i) 
		cache[i] = (cache[i - 1] + cache[i - 2]) % 10007;
	cout << cache[n] << endl;
	return 0;
}
