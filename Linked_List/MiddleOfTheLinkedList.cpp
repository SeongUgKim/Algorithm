class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

ListNode* middleNode(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    count /= 2;
    temp = head;
    for (int i = 0; i < count; ++i)
    {
        temp = temp->next;
    }
    return temp;
}



