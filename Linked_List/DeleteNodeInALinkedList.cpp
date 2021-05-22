class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

void deleteNode(ListNode* node) {
    ListNode* temp = node;
    while (temp->next != nullptr)
    {
        temp->val = temp->next->val;
        temp = temp->next;
    }
    temp = node;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
}