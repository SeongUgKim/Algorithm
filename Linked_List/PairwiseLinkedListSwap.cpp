class LLNode 
{
public:
    int val;
    LLNode* next;
};

LLNode* solve(LLNode* node) {
    LLNode* temp = node;
    while (temp != nullptr && temp->next != nullptr) {
        int tmp = temp->val;
        temp->val = temp->next->val;
        temp->next->val = tmp;
        temp = temp->next->next;
    }
    return node;
}