#include <string>
using namespace std;
int solve(string s) {
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n;) {
        count++;
        int j = i + 1;
        bool noninc = true;
        bool nondec = true;
        while (j < n) {
            if (s[j] > s[j - 1]) noninc = false;
            if (s[j] < s[j - 1]) nondec = false;
            if (!(noninc || nondec)) break;
            j++;
        }
        i = j;
    }
    return count;
}