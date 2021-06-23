#include "stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node)
{
    ListNode* p = node;
    while (p->next->next != nullptr)
    {
        p->val = p->next->val;
        p = p->next;
    }
    p->val = p->next->val;
    ListNode* tmp = p->next;
    p->next = p->next->next;
    delete tmp;
    
}