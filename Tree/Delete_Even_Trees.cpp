class Tree {
public:
		int val;
		Tree *left;
		Tree *right;
};
// solution 1
bool check(Tree* root) {
    if (!root) return false;
    if (!root->left && !root->right) {
        if (root->val % 2 == 0) return true;
        return false;
    }
    return check(root->left) || check(root->right);
}

Tree* help(Tree* root) {
    if (!root) return nullptr;
    if (!root->left && !root->right) {
        if (root->val % 2 == 0) return nullptr;
        return root;
    }
    root->left = help(root->left);
    root->right = help(root->right);
    return root;
}

Tree* solve(Tree* root) {
    bool flag = true;
    while (flag) {
        flag = check(root);
        if (!flag) break;
        root = help(root);
    }
    return root;
}
// solution 2
Tree* solve(Tree* root) {
    if (!root) return nullptr;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if (!root->left && !root->right && root->val % 2 == 0) return nullptr;
    return root;
}
