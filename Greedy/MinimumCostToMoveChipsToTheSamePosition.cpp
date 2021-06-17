#include <vector>
#include <unordered_set>
using namespace std;
int minCostToMoveChips(vector<int>& position) {
    unordered_set<int> st;
    for (int a : position)
    {
        st.insert(a);
    }
    sort(position.begin(), position.end());
    int n = position.size();
    int largest = position[n - 1];
    int mi = INT_MAX;
    int sum = 0;
    for (int i : st)
    {
        for (int j = 0; j < n; ++j)
        {
            int diff = position[j] - i;
            sum += diff % 2 == 0 ? 0 : 1;
        }
        mi = min(mi, sum);
        sum = 0;
    }
    return mi;
}
