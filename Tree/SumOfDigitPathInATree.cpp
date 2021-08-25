class Tree {
public:
    int val;
    Tree *left;
    Tree *right;
};
int sum;
void dfs(Tree* root, int curr) {
    curr *= 10;
    curr += root->val;
    if (root->right) dfs(root->right, curr);
    if (root->left) dfs(root->left, curr);
    if (!root->right && !root->left) sum += curr;
}
int solve(Tree* root) {
    sum = 0;
    dfs(root, 0);
    return sum;
} 