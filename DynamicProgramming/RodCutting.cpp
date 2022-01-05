#include <cstring>
#include <vector>
#include <climits>
using namespace std;
int cache[1001];
int topdown(vector<int>& prices, int length) {
	if (length == 0) return 0;
	int& res = cache[length];
	if (res != -1) return res;
	int ret = INT_MIN;
	for (int i = 0; i < prices.size(); ++i) {
		if (length < i + 1) break;
		ret = max(ret, prices[i] + topdown(prices, length - i - 1));
	}
	return res = ret;
}
