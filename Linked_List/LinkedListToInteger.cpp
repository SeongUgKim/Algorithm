#include "stdc++.h"
using namespace std;

class LLNode {
    public:
        int val;
        LLNode *next;
};

int solve(LLNode* node)
{
    vector<int> v;
    LLNode* p = node;
    while (p != nullptr)
    {
        v.push_back(p->val);
        p = p->next;
    }
    int start = 0;
    int end = v.size() - 1;
    while (start < end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    }
    int ret;
    for (int i = 0; i < v.size(); ++i)
    {
        ret += v[i] * pow(2, i);
    }
    return ret;
}

int main()
{

    return 0;
}
