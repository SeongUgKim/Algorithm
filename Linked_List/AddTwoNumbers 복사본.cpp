#include "stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* solve(ListNode* l1, ListNode* l2)
{
    /*    vector<int> list1;
    vector<int> list2;

    ListNode* p = l1;
    ListNode* q = l2;
    while (p != nullptr)
    {
        list1.push_back(p->val);
        p = p->next;
    }
    while (q != nullptr)
    {
        list2.push_back(q->val);
        q = q->next;
    }
    int carry = 0;
    int size1 = list1.size();
    int size2 = list2.size();
    vector<int> res;
    int temp = 0;
    if (size1 > size2)
    {
        for (int i = 0; i < size2; ++i)
        {
            temp = list1[i] + list2[i];
            if (carry == 1)
            {
                temp++;
                carry = 0;
            }
            if (temp >= 10)
            {
                carry = 1;
                temp = temp % 10;
            }
            res.push_back(temp);
        }
        for (int i = size2; i < size1; ++i)
        {
            temp = list1[i];
            if (carry == 1)
            {
                temp++;
                carry = 0;
            }
            if (temp >= 10)
            {
                carry = 1;
                temp = temp % 10;
            }
            res.push_back(temp);
        }
    }
    else
    {
        for (int i = 0; i < size1; ++i)
        {
            temp = list1[i] + list2[i];
            if (carry == 1)
            {
                temp++;
                carry = 0;
            }
            if (temp >= 10)
            {
                carry = 1;
                temp = temp % 10;
            }
            res.push_back(temp);
        }
        for (int i = size1; i < size2; ++i)
        {
            temp = list2[i];
            if (carry == 1)
            {
                temp++;
                carry = 0;
            }
            if (temp >= 10)
            {
                carry = 1;
                temp = temp % 10;
            }
            res.push_back(temp);
        }
    }
    if (carry == 1)
    {
        res.push_back(carry);
    }
    ListNode* ret = new ListNode();
    ListNode* r = ret;
    for (int i = 0; i < res.size() - 1; ++i)
    {
        r->val = res[i];
        ListNode* temp = new ListNode();
        r->next = temp;
        r = r->next;
    }
    r->val = res[res.size() - 1];
    r->next = nullptr;
    return ret;*/
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
        int num = 0;
        if (l1 != nullptr)
        {
            num += l1->val;
            l1= l1->next;
        }
        if (l2 != nullptr)
        {
            num += l2->val;
            l2 = l2->next;
        }
        if (carry == 1)
        {
            num++;
            carry = 0;
        }
        if (num >= 10)
        {
            carry = 1;
            num -= 10;
        }
        p->next = new ListNode(num);
        p = p->next;
    }
    if (carry == 1)
    {
        p->next = new ListNode(1);
    }
    return head->next;
}