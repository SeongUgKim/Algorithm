#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // int dx[4] = {0, 0, 1, -1};
        // int dy[4] = {1, -1, 0, 0};
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                int count = 4;
                // for (int k = 0; k < 4; ++k) {
                //     if (i + dy[k] >= 0 && i + dy[k] < m && j + dx[k] >= 0 && j + dx[k] < n && grid[i + dy[k]][j + dx[k]] == 1) {
                //         count--;
                //     }
                // }
                if (i - 1 >= 0 && grid[i - 1][j] == 1) count--;
                if (i + 1 < m && grid[i + 1][j] == 1) count--;
                if (j - 1 >= 0 && grid[i][j - 1] == 1) count--;
                if (j + 1 < n && grid[i][j + 1] == 1) count--;
                ret += count;
            }
        }
        return ret;
    }
};
