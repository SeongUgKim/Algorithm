class Pair {
    int row;
    int col;
    public Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

class Solution {
    public int getFood(char[][] grid) {
        Queue<Pair> queue = new LinkedList<>();
        int m = grid.length;
        int n = grid[0].length;
        boolean flag = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    queue.add(new Pair(i, j));
                    grid[i][j] = 'X';
                }
                if (grid[i][j] == '#') flag = true;
            }
        }
        if (flag == false) return -1;
        boolean[][] visited = new boolean[m][n];
        int level = 0;
        int[] drow = {-1, 0, 1, 0};
        int[] dcol = {0, 1, 0, -1};
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int j = 0; j < size; ++j) {
                Pair p = queue.remove();
                int row = p.row;
                int col = p.col;
                if (grid[row][col] == '#') return level;
                for (int i = 0; i < 4; ++i) {
                    int newRow = row + drow[i];
                    int newCol = col + dcol[i];
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n) continue;
                    if (grid[newRow][newCol] == 'X') continue;
                    if (visited[newRow][newCol]) continue;
                    visited[newRow][newCol] = true;
                    queue.add(new Pair(newRow, newCol));
                }
            }
            level++;
        }
        return -1;
    }
}
