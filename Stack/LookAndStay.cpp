#include <string>
using namespace std;
string solve(int n) {
	if (n == 1) return "1";
	if (n == 2)  return "11";
	string res = solve(n - 1);
	string ret = "";
	int count = 1;
	char start = res[0];
	int i;
	for (i = 1; i < res.size(); ++i) {
		if (res[i] != start) {
			ret += (count + '0');
			ret += start;
			count = 1;
			start = res[i];
			continue;
		}
		count++;
	}
	if (count != 0) {
		ret += (count + '0');
		ret += start;
	}
	return ret;
}
