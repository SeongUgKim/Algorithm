#include <queue>
#include <vector>
using namespace std;

int solve(vector<int>& cells) {
    priority_queue<int> pq;
    for (int& cell : cells) {
        pq.push(cell);
    }
    int diff;
    while (!pq.empty()) {
        if (pq.size() == 1) return pq.top();
        int last = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if (last != second) {
            diff = (last + second) / 3;
            pq.push(diff);
        }
    }
    return -1;
}