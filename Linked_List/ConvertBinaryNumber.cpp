#include "stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode* head)
{
    stack<int> number;
    ListNode* p = head;
    while (p != nullptr)
    {
        number.push(p->val);
        p = p->next;
    }
    int ret = 0;
    int i = 0;
    while (!number.empty())
    {
        ret += (int)pow(2, i++) * number.top();
        number.pop();
    }
    return ret;
}
