#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for (auto& update : updates) {
            int start = update[0];
            int end = update[1];
            int val = update[2];
            ans[start] += val;
            if (end < length - 1) ans[end + 1] -= val;
        }
        partial_sum(ans.begin(), ans.end(), ans.begin());
        return ans;
    }
};
