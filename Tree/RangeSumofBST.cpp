class Solution {
public:
    // input : root node, low boundary, and high boundary
    // output : sum of node values from low to high (inclusive)
    // dfs -> inorder style
    // if the value is in between low and high, add to the result value
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        if (root->val >= low && root->val <= high) return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
