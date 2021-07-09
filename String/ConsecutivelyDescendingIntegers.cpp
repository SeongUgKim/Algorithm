#include <stack>
#include <vector>
#include <string>
using namespace std;
bool solve(string s) {
    stack<int> st;
    int n = s.size();
    for (int i = 1; i <= 5; ++i) {
        int len = i;
        int j = 0;
        string first = s.substr(0, len);
        j += len;
        int first_num = stoi(first);
        if (first_num == 10 || first_num == 100 || first_num == 1000 || first_num == 10000) len--;
        st.push(std::stoi(first));
        while (j < n) {
            int larger = st.top();
            string comp = s.substr(j, len);
            j += len;
            int num = stoi(comp);
            if (num == 10 || num == 100 || num == 1000 || num == 10000) len--;
            if (len == 0 && j != n) {
                while (!st.empty()) {
                    st.pop();
                }
                break;
            }
            if (num + 1 == larger) st.push(num);
            else {
                while (!st.empty()) {
                    st.pop();
                }
                break;
            }
        }
        if (j == n && st.size() > 1) return true;
    }
    return false;
}