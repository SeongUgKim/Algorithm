#include <vector>
using namespace std;

vector<vector<int>> visited;
int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
    if (grid[i][j] == 0) return 0;
    int temp = grid[i][j];
    grid[i][j] = 0;
    int ans = max({dfs(grid, i - 1, j), dfs(grid, i + 1, j), dfs(grid, i, j - 1), dfs(grid, i, j + 1)});
    grid[i][j] = temp;
    return grid[i][j] + ans;
}
int getMaximumGold(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if(grid[i][j] == 0) continue;
            visited.clear();
            visited.resize(grid.size(), (vector<int>(grid[0].size(), 0)));
            ans = max(ans, dfs(grid, i, j));
            cout << ans << endl;
        }
    }
    return ans;
}
