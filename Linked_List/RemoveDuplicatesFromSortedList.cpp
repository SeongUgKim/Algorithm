class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)
    {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr)
    {
        while (slow->val == fast->val)
        {
            ListNode* temp = fast;
            slow->next = fast->next;
            fast = slow->next;
            delete temp;
            if (fast == nullptr)
            {
                return head;
            }
        }
        slow = slow->next;
        fast = slow->next;
    }
    return head;
}