#include <vector>
using namespace std;
int solve(vector<vector<string>>& matrix, vector<string>& blocks) {
    unordered_map<string, pair<int, int>> mp;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            mp[matrix[i][j]] = make_pair(i, j);
        }
    }
    vector<pair<int, int>> vec;
    // vector 사용 하지 않아 도 됨
    for (int i = 0; i < blocks.size(); ++i)
    {
        vec.push_back(mp[blocks[i]]);
    }
    int distance = vec[0].first + vec[0].second;
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        int x0 = vec[i].first;
        int x1 = vec[i + 1].first;
        int y0 = vec[i].second;
        int y1 = vec[i + 1].second;
        int temp = abs(x0 - x1) + abs(y0 - y1);
        distance += temp;
    }
    return distance;
}