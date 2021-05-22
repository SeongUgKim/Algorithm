class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* output = new ListNode(0);
    ListNode* cur = output;
    int carry = 0;
    while (p != nullptr || q != nullptr)
    {
        int x = p != nullptr ? p->val : 0;
        int y = q != nullptr ? q->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (p != nullptr)
        {
            p = p->next;
        }
        if (q != nullptr)
        {
            q = q->next;
        }
    }
    if (carry != 0)
    {
        cur->next = new ListNode(carry);
    }
    return output->next;
}



