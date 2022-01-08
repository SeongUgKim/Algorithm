#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	int time;
	vector<int> vec;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> time;
		vec.push_back(time);
	}
	sort(vec.begin(), vec.end());
	int sum = vec[0];
	for (int i = 1; i < num; ++i) {
		vec[i] = vec[i] + vec[i - 1];
		sum += vec[i];
	}
	cout << sum << endl;
}
