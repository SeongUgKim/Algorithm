#include "stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head)
{
    unordered_map<ListNode*, int> map;
    ListNode* list = head;
    while (list != nullptr)
    {
        map[list]++;
        if (map[list] > 1)
        {
            return true;
        }
        list = list->next;
    }
    return false;
}

int main()
{
    ListNode* l1 = new ListNode(3);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(0);
    ListNode* l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = nullptr;
    ListNode* head = l1;
    cout << hasCycle(head) << endl;
    return 0;
}