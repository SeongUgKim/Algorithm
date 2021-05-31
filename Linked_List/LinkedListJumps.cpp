class LLNode {
public:
    int val;
    LLNode* next;
};

LLNode* solve(LLNode* node) {
    LLNode* temp = node;
    while (temp != nullptr)
    {
        int n = temp->val - 1;
        for (int i = 0; i < n; ++i)
        {
            if (temp == nullptr)
            {
                break;
            }
            LLNode* t = temp->next;
            temp->next = t != nullptr ? t->next : nullptr;
            delete t;
        }
        if (temp == nullptr)
        {
            break;
        }
        temp = temp->next;
    }
    return node;
}
