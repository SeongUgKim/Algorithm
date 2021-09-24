#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = n - 1;
    int j = m - 1;
    int count = 0;
    while (i >= 0 && j >= 0) {
        if (g[i] > s[j]) i--;
        else {
            i--;
            j--;
            count++;
        }
    }
    return count;
}