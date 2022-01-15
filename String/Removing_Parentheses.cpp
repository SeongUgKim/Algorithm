#include <string>
using namespace std;

int solve(string s) {
    int open = 0;
    int ret = 0;
    for (char c : s) {
        if (c == '(') open++;
        if (c == ')') {
            if (open == 0) ret++;
            else open--;
        }
    }
    return ret + open;
}
