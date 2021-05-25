#include <stack>
using namespace std;
bool isValid(string s) {
    stack<char> p;
    for (auto c : s)
    {
        if (c == '(')
        {
            p.push(')');
        }
        else if (c == '{')
        {
            p.push('}');
        }
        else if (c == '[')
        {
            p.push(']');
        }
        else
        {
            if (p.empty())
            {
                return false;
            }
            if (c != p.top())
            {
                return false;
            }
            p.pop();
        }
    }
    return p.empty();
}

