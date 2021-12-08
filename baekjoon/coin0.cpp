#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(int a, int b) {
        return a > b;
}


int main()
{
        int N;
        int K;
        cin >> N >> K;
        vector<int> coins(N);
        for (int i = 0; i < N; ++i) {
                cin >> coins[i];
        }
        int ans = 0;
        sort(coins.begin(), coins.end(), cmp);
        for (int i = 0; i < N; ++i) {
                while (K - coins[i] >= 0) {
                        ans++;
                        K -= coins[i];
                }
        }
        cout << ans << endl;
}
