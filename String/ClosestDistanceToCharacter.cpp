#include <vector>
using namespace std;
vector<int> solve(string s, string c) {
    int prev = -1;
    int next = 0;
    int current = 0;
    int n = s.size();
    int diff = 0;
    vector<int> res;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == c[0])
        {
            next = i;
            break;
        }
    }
    while (current < n)
    {
        if (prev == -1)
        {
            diff = abs(current - next);
        }
        else
        {
            diff = min(abs(current - prev), abs(current - next));
        }
        res.push_back(diff);
        if (current == next)
        {
            prev = next;
            for (int i = next + 1; i < n; i++)
            {
                if (s[i] == c[0])
                {
                    next = i;
                    break;
                }
            }
        }
        current++;
    }
    return res;
}