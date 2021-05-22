#include <unordered_map>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, int> mp;
    ListNode* list1 = headA;
    ListNode* list2 = headB;
    while (list1 != nullptr)
    {
        mp[list1]++;
        list1 = list1->next;
    }
    while (list2 != nullptr)
    {
        if (mp[list2] == 1)
        {
            break;
        }
        list2 = list2->next;
    }
    return list2;
}

ListNode* solve(ListNode *headA, ListNode *headB) {
    ListNode* list1 = headA;
    ListNode* list2 = headB;
    while (list1 != nullptr)
    {
        list1->val *= -1;
        list1 = list1->next;
    }
    while (list2 != nullptr)
    {
        if (list2->val < 0)
        {
            break;
        }
        list2 = list2->next;
    }
    list1 = headA;
    while (list1 != nullptr)
    {
        list1->val *= -1;
        list1 = list1->next;
    }
    return list2;
}
