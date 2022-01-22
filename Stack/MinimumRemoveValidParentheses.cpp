#include <string>
#include <stack>
string minRemoveToMakeValid(string s) {
    stack<int> st;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        }
        if (s[i] == ')') {
            if (st.empty()) s[i] = '#';
            else st.pop();
        }
    }
    while (!st.empty()) {
        s[st.top()] = '#';
        st.pop();
    }
    string ans = "";
    for (char c : s) {
        if (c == '#') continue;
        ans += c;
    }
    return ans;
}
