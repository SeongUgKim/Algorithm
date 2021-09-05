class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        val = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* CopyTreeRecursive(Node* root)
{
    if (!root) return nullptr;
    Node* node = new Node(root->val);
    node->left = CopyTreeRecursive(root->left);
    node->right = CopyTreeRecursive(root->right);
    return node;
}