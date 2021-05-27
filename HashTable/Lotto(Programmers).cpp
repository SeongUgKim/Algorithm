#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    unordered_set<int> st;
    unordered_map<int, int> mp;
    vector<int> res;
    mp[6] = 1;
    mp[5] = 2;
    mp[4] = 3;
    mp[3] = 4;
    mp[2] = 5;

    for (int a : win_nums)
    {
        st.insert(a);
    }
    int zero_count = 0;
    int win_count = 0;
    for (int a : lottos)
    {
        if (a == 0)
        {
            zero_count++;
        }
        if (st.count(a))
        {
            win_count++;
        }
    }
    int lowest = win_count;
    int highest = win_count + zero_count;
    if (mp.count(highest))
    {
        res.push_back(mp[highest]);
    }
    else
    {
        res.push_back(6);
    }
    if (mp.count(lowest))
    {
        res.push_back(mp[lowest]);
    }
    else
    {
        res.push_back(6);
    }
    return res;
}