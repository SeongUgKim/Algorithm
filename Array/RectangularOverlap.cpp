#include <vector>
using namespace std;
bool solve(vector<int>& rect0, vector<int>& rect1) {
    if (rect0[0] >= rect1[2] || rect0[2] <= rect1[0] || rect0[1] >= rect1[3] || rect0[3] <= rect1[1]) return false;
    return true;
}