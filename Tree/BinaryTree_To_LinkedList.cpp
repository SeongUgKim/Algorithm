LLNode* res;
LLNode* tmp;
void inorder(Tree* root) {
    if (!root) return;
    inorder(root->left);
    tmp->next = new LLNode(root->val);
    tmp = tmp->next;
    inorder(root->right);
}
LLNode* solve(Tree* root) {
    if (!root) return nullptr;
    res = new LLNode(-1);
    tmp = res;
    inorder(root);
    res = res->next;
    return res;
}
