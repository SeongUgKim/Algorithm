#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int numIslandsBFS(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;
                count++;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        if (p.first + dy[k] >= 0 && p.first + dy[k] < m && p.second + dx[k] >= 0 && p.second + dx[k] < n && grid[p.first + dy[k]][p.second + dx[k]] == '1') {
                            q.push({p.first + dy[k], p.second + dx[k]});
                            grid[p.first + dy[k]][p.second + dx[k]] = '0';
                        }
                    }
                }
            }
        }
        return count;
    }
		void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '2' || grid[i][j] == '0') return;
        grid[i][j] = '2';
        for (int k = 0; k < 4; ++k) {
            dfs(grid, i + dy[k], j + dx[k]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
