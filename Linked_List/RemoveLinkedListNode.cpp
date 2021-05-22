class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr)
    {
        return head;
    }
    ListNode* cur = head;
    if (cur->val == val)
    {
        while (cur != nullptr && cur->val == val)
        {
            ListNode* temp = cur;
            head = cur->next;
            cur = head;
            delete temp;
        }
    }
    if (head == nullptr)
    {
        return head;
    }
    while (cur != nullptr)
    {
        if (cur->next != nullptr && cur->next->val == val)
        {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            delete temp;
            continue;
        }
        cur = cur->next;
    }
    return head;
}

ListNode* solve(ListNode* head, int val) {
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