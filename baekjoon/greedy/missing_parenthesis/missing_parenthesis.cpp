#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	string line;
	cin >> line;
	int n = line.size();
	int i = 0;
	int j = 0;
	bool is_neg = false;
	for (; i < n; ++i) {
		if (line[i] == '-') is_neg = true;
		if (line[i] == '+')
			if (is_neg) line[i] = '-';
	}
	i = 0;
	vector<int> number;
	vector<char> op;
	while (i < n && j < n) {
		while (line[j] >= '0' && line[j] <= '9') { 
		   	j++;
			if (j == n) break;
		}
		int power = j - i;
		int d = 0;
		while (i < j) d += ((line[i++] - '0') * pow(10, --power));
		number.push_back(d);
		if (i == n) break;
		op.push_back(line[i++]);
		if (i == n) break;
		j = i;
	}
	int N = number.size();	
	int res = number[0];
	for (i = 1; i < N; ++i) { 
		if (op[i - 1] == '+') res += number[i];
		if (op[i - 1] == '-') res -= number[i];	
	}
	cout << res << endl;
}





