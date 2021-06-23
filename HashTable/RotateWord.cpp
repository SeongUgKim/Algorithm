#include "stdc++.h"
#include <unordered_set>
using namespace std;

int solve(vector<string>& words)
{
    unordered_set<string> set;
    for (string s : words)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            rotate(s.begin(), s.begin() + 1, s.end()); // rotate method 
            if (set.count(s))
            {
                break;
            }
        }
        set.insert(s);
    }
    return set.size();
}

int main()
{
    vector<string> words = {"abc", "xy", "yx", "z", "bca"};
    cout << solve(words) << endl;
    return 0;
}