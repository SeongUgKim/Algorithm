#include "stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr && l2 == nullptr)
    {
        return nullptr;
    }
    if (l1 == nullptr)
    {
        return l2;
    }
    if (l2 == nullptr)
    {
        return l1;
    }
    ListNode* head;
    ListNode* ret;
    if (l1->val <= l2 ->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else 
    {
        head = l2;
        l2 = l2->next;
    }
    ret = head;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2 -> val)
        {
            head->next = l1;
            l1 = l1->next;
        }
        else 
        {
            head->next = l2;
            l2 = l2->next;
        }
        head->next->next = nullptr;
        head = head->next;
    }
    if (l1 == nullptr && l2 != nullptr)
    {
        head->next = l2;
    } 
    else if (l1 != nullptr && l2 == nullptr)
    {
        head->next = l1;
    }
    return ret;

    
}