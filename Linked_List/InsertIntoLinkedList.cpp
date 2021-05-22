class LLNode {
    public:
        int val;
        LLNode* next;
};

LLNode* solve(LLNode* head, int pos, int val) {
    LLNode* newNode = new LLNode();
    newNode->val = val;
    LLNode* temp = head;
    temp = head;

    for (int i = 0; i < pos - 1; ++i)
    {
        temp = temp->next;
    }
    if (temp == head && pos == 0) 
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;

}