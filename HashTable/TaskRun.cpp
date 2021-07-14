#include <vector>
#include <unordered_map>
using namespace std;
int bruteforce(vector<int>& tasks, int k) {
    int n = tasks.size();
    if (n == 0) return k = 0;
    unordered_map<int, int> mp;
    if (k > 100000) {
        for (int i = 0; i < n; ++i) {
            mp[tasks[i]] ++;
        }
        int count = 0;
        int uncount = 0;
        for (auto m : mp) {
            int add = m.second - 1;
            if (add == 0) uncount++;
            count += add;
        }
        return (n - uncount) + k * count;
    }
    int i = 0;
    int index = 0;
    int count = 0;
    while (i < n) {
        int num = tasks[i];
        if (mp.find(num) != mp.end()) {
            int diff = index - mp[num];
            if (diff > k) {
                count++;
                mp[num] = index;
                index++;
                i++;
            }
            else {
                count++;
                index++;
            }
        }
        else {
            count++;
            mp[num] = index;
            i++;
            index++;
        }
    }
    return count;
}

int solve(vector<int>& tasks, int k) {
    unordered_map<int, int> mp;
    int curr = 0;
    for (int t : tasks) {
        if (mp.count(t)) {
            curr = max(curr, mp[t] + k + 1);
        }
        mp[t] = curr++;
    }
    return curr;
}