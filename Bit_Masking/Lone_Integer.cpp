#include<vector>
using namespace std;
int solve(vector<int>& nums) {
    vector<int> bits(32);
    for (int i : nums) {
        for (int j = 0; j < 31; ++j) {
            if ((i & (1 << j)) != 0) bits[j]++;
        }
    }
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        if (bits[i] % 3 != 0) res |= (1 << i);
    }
    return res;
}
