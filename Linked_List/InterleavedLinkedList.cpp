class LLNode {
public:
    int val;
    LLNode* next;
};


LLNode* solve(LLNode* l0, LLNode* l1) {
    LLNode* dummyHead = new LLNode();
    LLNode* temp = dummyHead;
    LLNode* ptr1 = l0;
    LLNode* ptr2 = l1;
    while (ptr1 != nullptr || ptr2 != nullptr)
    {
        if (ptr1 != nullptr)
        {
            temp->next = ptr1;
            ptr1 = ptr1->next;
            temp = temp->next;
        }
        if (ptr2 != nullptr)
        {
            temp->next = ptr2;
            ptr2 = ptr2->next;
            temp = temp->next;
        }
    }
    return dummyHead->next;
}