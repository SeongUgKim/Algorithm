#include <unordered_set>
#include "stdc++.h"
using namespace std;

int solve(string animals, string dinosaurs)
{
    unordered_set<char> st;
    int res = 0;
    for (auto c : dinosaurs)
    {
        st.insert(c);
    }

    for (auto c : animals)
    {
        if (st.count(c))
        {
            res++;
        }
    }
    return res;
}