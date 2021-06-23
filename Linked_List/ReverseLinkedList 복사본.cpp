#include "stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) 
{
    ListNode* cur = nullptr;
    while (head != nullptr)
    {
        ListNode* next = head->next;
        head->next = cur;
        cur = head;
        head = next;
    }
    return cur;

}
