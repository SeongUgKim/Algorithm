#include <unordered_map>
using namespace std;
bool solve(string s) {
    unordered_map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
    }
    bool flag = false;
    for (auto m : mp)
    {
        if (flag == false)
        {
            if (m.second % 3 != 0 && m.second % 3 != 2)
            {
                return false;
            }
            if (m.second % 3 == 2)
            {
                flag = true;
            }
        }
        else
        {
            if (m.second % 3 != 0)
            {
                return false;
            }
        }
    }
    return flag;

}