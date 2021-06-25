#include <string>
using namespace std;
string solve(string s) {
    string res = "";
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (i + 1 != n && s[i] == '<' && s[i + 1] == '-') {
            i++;
            if (res.size() != 0) res.pop_back();
        }
        else {
            res += s[i];
        }
    }
    return res;
}

int main() 
{
    return 0;
}