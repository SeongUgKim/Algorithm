int solve(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> v1;
    vector<int> v2;
    int mx = INT_MIN;
    for (int i = 0; i < m; ++i) {
        mx = INT_MIN;
        for (int j = 0; j < n; ++j) {
            mx = max(mx, matrix[i][j]);
        }
        v1.push_back(mx);
    }
    for (int j = 0; j < n; ++j) {
        mx = INT_MIN;
        for (int i = 0; i < m; ++i) {
            mx = max(mx, matrix[i][j]);
        }
        v2.push_back(mx);
    }
    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == v1[i] && matrix[i][j] == v2[j]) count++;
        }
    }

    return count;
}

