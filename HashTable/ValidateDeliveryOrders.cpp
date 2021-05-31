#include <unordered_map>
#include <vector>
using namespace std;
bool solve(vector<string>& orders) {
    unordered_map<int, int> mp;
    int check = 0;
    for (auto order : orders)
    {
        int val = stoi(order.substr(1));
        if (order[0] == 'P')
        {
            if (mp.count(val))
            {
                return false;
            }
            mp[val]++;
            check++;
        }
        else
        {
            if (mp[val] != 1)
            {
                return false;
            }
            mp[val]++;
            check--;
        }
    }
    return check == 0;
}