#include <vector>
#include <unordered_map>
using namespace std;
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    unordered_map<int, int> mp;
    vector<int> units;
    int n = boxTypes.size();
    for (int i = 0; i < n; ++i) {
        mp[boxTypes[i][1]] += boxTypes[i][0];
    }
    for (auto m : mp) {
        units.push_back(m.first);
    }
    sort(units.begin(), units.end());
    n = units.size();
    int sum = 0;
    for(int i = n - 1; i >= 0; --i) {
        int unit = units[i];
        int quant = min(truckSize, mp[units[i]]);
        sum += unit * quant;
        truckSize -= quant;
        if (truckSize == 0) break;
    }
    return sum;
}