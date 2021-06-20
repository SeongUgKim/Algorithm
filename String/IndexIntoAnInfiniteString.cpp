#include <string>
using namespace std;

string solve(string s, int i, int j) {
    int n = s.size();
    string res = "";
    while (i < j) {
        res += s[i % n];
        i++;
    }
    return res;
}

