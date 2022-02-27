class RottingOrange {
    public int orangesRotting(int[][] grid) {
        int fresh = 0;
        int m = grid.length;
        int n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int[][] visited = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    int[] temp = new int[2];
                    temp[0] = i;
                    temp[1] = j;
                    queue.add(temp);
                    visited[i][j] = 1;
                }
            }
        }
        int[] drow = {-1, 0, 1, 0};
        int[] dcol = {0, 1, 0, -1};
        int level = 0;
        while (!queue.isEmpty()) {
            boolean flag = false;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                int[] temp = queue.remove();
                int row = temp[0];
                int col = temp[1];
                for (int j = 0; j < 4; ++j) {
                    int nRow = row + drow[j];
                    int nCol = col + dcol[j];
                    if (nRow < 0 || nRow >= m || nCol < 0 || nCol >= n) continue;
                    if (grid[nRow][nCol] == 2 || grid[nRow][nCol] == 0) continue;
                    int[] rot = new int[2];
                    rot[0] = nRow;
                    rot[1] = nCol;
                    queue.add(rot);
                    grid[nRow][nCol] = 2;
                    flag = true;
                }
            }
            if (flag == true) level++;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1; 
            }
        }
        return level;
    }
    public int orangesRottingRevision(int[][] grid) {
        Queue<Pair<Integer, Integer>> queue = new ArrayDeque();
        // step 1). Build the initial set of rotten oranges
        int freshOranges = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) queue.offer(new Pair(i, j));
                else if (grid[i][j] == 1) freshOranges++;
            }
        }
        // Mark the round / level 
        queue.offer(new Pair(-1, 1));
        // step 2 start the rotting process via BFS
        int minutesElapsed = -1;
        int[][] direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!queue.isEmpty()) {
            Pair<Integer, Integer> p = queue.poll();
            int row = p.getKey();
            int col = p.getValue();
            if (row == -1) {
                // we finish one round of processing
                minutesElapsed++;
                // to avlid the endless loop
                if (!queue.isEmpty()) queue.offer(new Pair(-1, -1));
            } else {
                // this is a rotten orange
                // then it would contaminate its neighbors
                for (int[] d : direction) {
                    int neighborRow = row + d[0];
                    int neighborCol = col + d[1];
                    if (neighborRow >= 0 && neighborRow < m && neighborCol >= 0 && neighborCol < n) {
                        if (grid[neighborRow][neighborCol] == 1) {
                            grid[neighborRow][neighborCol] = 2;
                            freshOranges--;
                            queue.offer(new Pair(neighborRow, neighborCol));
                        }
                    }
                }
            }
        }
        return freshOranges == 0 ? minutesElapsed : -1;
    }
}

