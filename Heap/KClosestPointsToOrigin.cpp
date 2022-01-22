#include <vector>
#include <priority_queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;
    priority_queue<vector<int>> maxHeap;
    for (int i = 0; i < points.size(); ++i) {
        int x = points[i][0];
        int y = points[i][1];
        maxHeap.push({x * x + y * y, x, y});
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    for (int i = 0; i < k; ++i) {
        vector<int> top = maxHeap.top();
        maxHeap.pop();
        ans.push_back({top[1], top[2]});
    }
    return ans;
}
