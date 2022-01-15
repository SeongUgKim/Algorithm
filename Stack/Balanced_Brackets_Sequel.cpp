#include <stack>
#include <string>
using namespace std;
bool solve(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{'  || ch == '[') st.push(ch);
        else {
            if (st.empty()) return false;
            if (ch == ')') {
                if (st.top() != '(') return false;
                st.pop();
            } else if (ch == '}') {
                if (st.top() != '{') return false;
                st.pop();
            } else {
                if (st.top() != '[') return false;
                st.pop();
            }
        }
    }
    return st.empty();
}
