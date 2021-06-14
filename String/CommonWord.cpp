#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solve(string s0, string s1) {
    string s = "";
    int m = s0.size();
    int n = s1.size();
    unordered_map<string, int> mp;
    unordered_set<string> st;
    for (int i = 0; i < m; ++i)
    {
        if (s0[i] == ' ')
        {
            mp[s]++;
            s = "";
            continue;
        }
        s += tolower(s0[i]);
    }
    mp[s]++;
    s = "";
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] == ' ')
        {
            if (s != "" && mp[s] != 0)
            {
                st.insert(s);
            }
            s = "";
            continue;
        }
        s += tolower(s1[i]);
    }
    if (s != "" && mp[s] != 0)
    {
        st.insert(s);
    }
    return st.size();
}