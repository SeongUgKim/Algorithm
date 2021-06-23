#include "stdc++.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val)
{
    ListNode** pp = &head;
    while (*pp != nullptr)
    {
        if ((*pp)->val == val)
        {
            ListNode* temp = *pp;
            *pp = (*pp)->next;
            delete temp;
        }
        else 
        {
            pp = &(*pp)->next;
        }
    }
    return head;
}