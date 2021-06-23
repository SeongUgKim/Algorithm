#include "stdc++.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode* listA = headA;
    ListNode* listB = headB;
    if (listA == nullptr)
    {
        return nullptr;
    }
    if (listB == nullptr)
    {
        return nullptr;
    }
    int countA = 0;
    int countB = 0;
    while (listA != nullptr)
    {
        countA++;
        listA = listA->next;
    }     
    while (listB != nullptr)
    {
        countB++;
        listB = listB->next;
    }
    listA = headA;
    listB = headB;
    if (countA > countB)
    {
        int diff = countA - countB;
        for (int i = 0; i < diff; ++i)
        {
            listA = listA->next;
        }
        while (listA != nullptr && listA != nullptr)
        {
            if (listA == listB)
            {
                return listA;
            }
            listA = listA->next;
            listB = listB->next;
        }
        return nullptr;
    }   
    else if (countA == countB)
    {
        while (listA != nullptr && listB != nullptr)
        {
            if (listA == listB)
            {
                return listA;
            }
            listA = listA->next;
            listB = listB->next;
        }
        return nullptr;
    }
    else 
    {
        int diff = countB - countA;
        for (int i = 0; i < diff; ++i)
        {
            listB = listB->next;
        }
        while (listA != nullptr && listB != nullptr)
        {
            if (listA == listB)
            {
                return listA;
            }
            listA = listA->next;
            listB = listB->next;
        }
        return nullptr;
    }
}