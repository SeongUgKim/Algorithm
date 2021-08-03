class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool help(TreeNode* root, TreeNode* subRoot, bool flag) {
    if (!root && !subRoot) return true;
    if (!root || !subRoot) return false;
    if (root->val != subRoot->val && flag == false) return help(root->right, subRoot, flag) || help(root->left, subRoot, flag);
    if (root->val != subRoot->val && flag) return false;
    if (flag) {
        return help(root->right, subRoot->right, flag) && help(root->left, subRoot->left, flag);   
    }
    return (help(root->right, subRoot->right, true) && help(root->left, subRoot->left, true)) || (help(root->right, subRoot, flag) || help(root->left, subRoot, flag));
    
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    return help(root, subRoot, false);
}

bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return (root1->val == root2->val) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    if (isSameTree(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}