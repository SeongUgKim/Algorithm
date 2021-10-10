class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};
int num;
void help(Tree* root) {
    if (!root) return;
    bool flag = false;
    if (!root->left && root->right) flag = true;
    if (!root->right && root->left) flag = true;
    if (flag) num++;
    help(root->left);
    help(root->right);
}
int solve(Tree* root) {
    num = 0;
    help(root);
    return num;
}