int res;
void help(Tree* parent, Tree* root, int k) {
    if (!root) return;
    if (root->val == k) {
        res = parent->left->val == k ? parent->right->val : parent->left->val;
        return;
    }
    if (root->val < k) help(root, root->right, k);
    else help(root, root->left, k);
}
int solve(Tree* root, int k) {
   res = -1;
   help(nullptr, root, k);
   return res;
}
