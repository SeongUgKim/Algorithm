#include <vector>
#include <priority_queue>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int res = 0;
        if (sticks.size() == 1) return 0;
        priority_queue<int> pq;
        for (auto i : sticks) {
            pq.push(i * -1);
        }
        while (pq.size() > 1) {
            int sum = 0;
            sum += pq.top() * -1;
            pq.pop();
            sum += pq.top() * -1;
            pq.pop();
            res += sum;
            pq.push(sum * -1);
        }
        return res;
    }
};
