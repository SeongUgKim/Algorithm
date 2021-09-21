class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* newNode = nullptr;
        if (!root1 && !root2) {
            return newNode;
        }
        if (!root1) {
            newNode = new TreeNode(root2->val);
            newNode->left = mergeTrees(root1, root2->left);
            newNode->right = mergeTrees(root1, root2->right);
            return newNode;
        }
        if (!root2) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }