int maxLength = 0;
void dfs(TreeNode* root, TreeNode* parent, int length) {
    if (!root) return;
    if (parent && root->val == parent->val + 1) length++;
    else length = 1;
    maxLength = max(maxLength, length);
    dfs(root->left, root, length);
    dfs(root->right, root, length);
}
int longestConsecutive(TreeNode* root) {
    dfs(root, nullptr, 0);
    return maxLength;
}
