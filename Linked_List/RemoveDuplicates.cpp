struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
    if (head == nullptr)
    {
        return head;
    }

    ListNode* list = head;
    ListNode* ret = list;
    head = head->next;
    while (head != nullptr)
    {
        if (list->val == head->val)
        {
            ListNode* tmp = head;
            head = head->next;
            list->next = head;
            delete tmp;
        }
        else 
        {
            head = head->next;
            list = list->next;
        }
    }
    return ret;
}