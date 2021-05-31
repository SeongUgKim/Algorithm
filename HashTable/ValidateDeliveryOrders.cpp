#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
bool solve(vector<string>& orders) {
    unordered_map<int, int> mp;
    unordered_set<string> st;
    for (string order : orders)
    {
        st.insert(order);
    }
    if (st.size() != orders.size())
    {
        return false;
    }
    st.clear();
    for (string order: orders)
    {
        if (order[0] == 'P')
        {
            string code = "";
            for (int i = 1; i < order.size(); ++i)
            {
                code += order[i];
            }
            int number = stoi(code);
            mp[number]++;
            continue;
        }
        string code = "";
        for (int i = 1; i < order.size(); ++i)
        {
            code += order[i];
        }
        int number = stoi(code);
        if (mp[number] == 0)
        {
            return false;
        }
        if (mp[number] == 1)
        {
            mp[number]--;
            continue;
        }
    }
    for (auto m : mp)
    {
        if (m.second != 0)
        {
            return false;
        }
    }
    return true;
}
