#include <string>
using namespace std;
bool repeatedSubstringPattern(string s) {
    int n = s.size();
    string temp;
    bool flag;
    for (int len = 1; len <= n / 2; len++) {
        if (n % len != 0) continue;
        temp = s.substr(0, len);
        flag = true;
        for (int i = 0; i <= n - len; i += len) {
            if (temp != s.substr(i, len)) {
                flag = false; 
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}