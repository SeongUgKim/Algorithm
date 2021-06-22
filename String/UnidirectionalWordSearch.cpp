#include <vector>
#include <string>
using namespace std;
bool solve(vector<vector<string>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    string s = "";
    for (int i = 0; i < m; ++i) {
        s = "";
        for (int j = 0; j < n; ++j) {
            s += board[i][j];
            if (s.find(word) != string::npos) return true;
        }
    }
    for (int i = 0; i < n; ++i) {
        s = "";
        for (int j = 0; j < m; ++j) {
            s += board[j][i];
            if (s.find(word) != string::npos) return true;
        }
    }
    return false;
}