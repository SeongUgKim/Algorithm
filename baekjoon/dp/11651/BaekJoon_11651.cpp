#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
}

int main()
{
        int N, x, y;
        cin >> N;
        vector<pair<int, int>> vec;
        pair<int, int> temp;
        for (int i = 0; i < N; ++i) {
                cin >> temp.first >> temp.second;
                vec.push_back(temp);
        }
        sort(vec.begin(), vec.end(), compare);
        for (int i = 0; i < N; ++i) {
                cout << vec[i].first << ' ' << vec[i].second << '\n';
        }
        return 0;
}
