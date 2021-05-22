#include <stack>
#include <vector>
using namespace std;
vector<string> solve(vector<string>& path) {
    stack<string> st;
    vector<string> res;
    for (auto s : path) 
    {
        if (s == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
            continue;   
        }
        if (s == ".") 
        {
            continue;
        }
        st.push(s);
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}