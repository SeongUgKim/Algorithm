#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int N;
	vector<int> A;
	vector<int> B;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int d;
		cin >> d;
		A.push_back(d);
	}
	for (int i = 0; i < N; ++i) {
		int d;
		cin >> d;
		B.push_back(d);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		int c = A[i] * B[i];
		sum += c;
	}
	cout << sum << endl;
}
