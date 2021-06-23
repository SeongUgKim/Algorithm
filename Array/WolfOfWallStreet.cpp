#include "stdc++.h"
using namespace std;

int solve(vector<int>& prices)
{
    int lowestPrice = INT_MAX;
    int res = 0;
    for (auto a : prices)
    {
        lowestPrice = min(a, lowestPrice); // remember the minimum price
        res = max(res, a - lowestPrice);
    }
    return res;
}

int main()
{
    vector<int>prices = {1, 0};
    cout << solve(prices) << endl;
    return 0;
}