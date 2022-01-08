#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int K;
	cin >> K;
	vector<int> vec;
	for (int i = 0; i < N; ++i) { 
		int coin;
		cin >> coin;
		vec.push_back(coin);
	}
	int index = N - 1;
	int count = 0;
	while (K > 0) {
		if (vec[index] > K) {
			index--;
			continue;
		}
		count++;
		K -= vec[index];
	}
	cout << count << endl;
}



	
	

