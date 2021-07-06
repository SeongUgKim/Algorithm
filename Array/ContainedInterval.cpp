#include <vector>
using namespace std;
static bool compare (vector<int>& a, vector<int>& b) {
    if (a[0] < b[0]) return true;
    if (a[0] == b[0]) {
        if (a[1] >= b[1]) return true;
        return false;
    }
    return false;
}
bool solve(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    int n = intervals.size();
    int max_val = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (intervals[i][1] <= max_val) return true;
        max_val = intervals[i][1];
    }
    return false;
}