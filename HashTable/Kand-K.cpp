#include <vector>
using namespace std;
int solve(vector<int>& nums) {
    unordered_set<int> st;
    int res = -1;
    for (int i : nums)
    {
        if (i == 0)
        {
            res = max(res, 0);
        }
        else if (st.count(-i))
        {
            res = max(res, abs(i));
        }
        st.insert(i);
    }
    return res;

}