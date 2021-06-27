class LLNode {
public:
    int val;
    LLNode* next;
};

LLNode* solve(LLNode* node, int target) {
    LLNode* cur = node;
    LLNode* prev = nullptr;
    while (cur != nullptr) {
        if (cur->val == target) {
            if (prev == nullptr) {
                node = node->next;
                cur = node;
            }
            else {
                LLNode* temp = cur;
                cur = cur->next;
                prev->next = cur;
                delete temp;
            }
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return node;
}