class ListNode 
{
    public:
        int val;
        ListNode* next;
        ListNode() {
            val = 0;
            next = nullptr;
        }
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* output;
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
    if (temp1->val > temp2->val)
    {
        output = temp2;
        temp2 = temp2->next;
    }
    else 
    {
        output = temp1;
        temp1 = temp1->next;
    }
    ListNode* temp = output;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->val > temp2->val)
        {
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        else
        {
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        } 
    }
    if (temp1 != nullptr)
    {
        temp->next = temp1;
    }
    if (temp2 != nullptr)
    {
        temp->next = temp2;
    }
    return output;
}