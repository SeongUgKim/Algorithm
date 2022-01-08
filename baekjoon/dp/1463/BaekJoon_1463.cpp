#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cache[1000001];
	cache[0] = 0;
	cache[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (i % 2 == 0 && i % 3 == 0) {
			cache[i] = min(cache[i / 2], min(cache[i / 3], cache[i - 1])) + 1;
			continue;
		}
		if (i % 2 == 0) {
			cache[i] = min(cache[i / 2], cache[i - 1]) + 1;
			continue;
		}
		if (i % 3 == 0) {
			cache[i] = min(cache[i / 3], cache[i - 1]) + 1;
			continue;
		}
		cache[i] = cache[i - 1] + 1;
	}
	cout << cache[n] << endl;	
	return 0;
}



