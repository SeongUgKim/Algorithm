#include <stack>
using namespace std;
string solve(string s) {
    int n = s.size();
    stack<int> stack;
    string res = "";
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
        {
            stack.push(s[i] - '0');
            continue;
        }
        int k = 0;
        while (!stack.empty())
        {
            count += pow(10, k++) * stack.top();
            stack.pop();
        }
        for (int j = 0; j < count; ++j)
        {
            res += s[i];
        }
        count = 0;
    }
    return res;
}