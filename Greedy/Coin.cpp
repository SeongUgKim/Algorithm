#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int N;
int K;
int type[MAX];

void Input()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; ++i) cin >> type[i];
}

int Solution(int type[], int K, int index)
{
	if (index == N) return INT_MAX;
	return min({ Solution(type, K, index + 1), Solution(type, K - type[index], index + 1), Solution(type, K - type[index], index)});
}

void Solve()
{
	Input();
	int res = Solution(type, K, 0);
	cout << res << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Solve();
	return 0;
}