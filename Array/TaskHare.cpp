#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<int>& tasks, vector<int>& people) {
    sort(tasks.begin(), tasks.end());
    sort(people.begin(), people.end());
    int t = 0;
    int p = 0;
    while (t < tasks.size() && p < people.size()) {
        if (people[p] >= tasks[t]) {
            t++;
            p++;
        }
        else p++;
    }
    return t;
}

