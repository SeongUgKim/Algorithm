class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};
int ans;
void inorder(Tree* root, int& k) {
    if (!root) return;
    inorder(root->left, k);
    if (k == 0) ans = root->val;
    k--;
    inorder(root->right, k);
}
int solve(Tree* root, int k) {
   ans = 0;
   inorder(root, k);
   return ans;
}