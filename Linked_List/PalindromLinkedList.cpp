#include <vector>

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

bool isPalindrome(ListNode* head) {
    vector<int> v1;
    vector<int> v2;
    ListNode* temp = head;
    while (temp != nullptr)
    {
        v1.push_back(temp->val);
        temp = temp->next;
    }
    ListNode* prev = nullptr;
    ListNode* ptr = head;
    while (ptr != nullptr)
    {
        ListNode* temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    while (prev != nullptr)
    {
        v2.push_back(prev->val);
        prev = prev->next;
    }
    for (int i = 0; i < v1.size(); ++i)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

bool isPalindromeUsingStack(ListNode* head) {
    stack<int> st;
    ListNode* temp = head;
    while (temp != nullptr)
    {
        st.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (temp->val != st.top())
        {
            return false;
        }
        temp = temp->next;
        st.pop();
    }
    return true;
}