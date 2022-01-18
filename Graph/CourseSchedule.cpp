#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> order;
    int num;
    
    void makeGraph(vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        for (int i = 0; i < n; ++i) {
            adj[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }
    }
    
    void dfs(int here) {
        visited[here] = 1;
        for (int there = 0; there < num; ++there) {
            if (adj[here][there] && !visited[there]) {
                dfs(there);
            }
        }
        order.push_back(here);
    }
    
    bool topologicalSort() {
        for (int i = 0; i < num; ++i) {
            if (!visited[i]) {
                dfs(i);
            }   
        }
        reverse(order.begin(), order.end());
        for (int i = 0; i < num; ++i) {
            for (int j = i; j < num; ++j) {
                if (adj[order[j]][order[i]]) return false;
            }
        }
        return true;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        num = numCourses;
        adj = vector<vector<int>>(num, vector<int>(num, 0));
        visited = vector<int>(num, 0);
        order.clear();
        makeGraph(prerequisites);
        return topologicalSort();
    }
};
