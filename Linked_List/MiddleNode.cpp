#include "stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head)
{
    ListNode* p = head;
    int count = 0;
    while (p != nullptr)
    {
        coutn++;
        p = p->next;
    }
    int mid = count / 2;
    p = head;
    for (int i = 0; i < mid;  ++i)
    {
        p = p->next;
    }
    return p;
}