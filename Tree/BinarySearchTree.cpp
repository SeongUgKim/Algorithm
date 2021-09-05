class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

Node* GetNodeOrNull(Node* node, int data)
{
    if (!node) return nullptr;
    if (node->data == data) return node;
    if (node->data > data) return GetNodeOrNull(node->left, data);
    return GetNodeOrNull(node->right, data);
}

Node* InsertNode(Node* node, int data)
{
    if (!node) return nullptr;
    if (node->data > data) node->left = InsertNode(node->left, data);
    else node->right = InsertNode(node->right, data);
    return node;
}

Node* GetMaxValueNode(Node* node)
{
    Node* temp = node;
    while (temp && temp->right)
    {
        temp = temp->right;
    }
    return temp;
}

Node* DeleteNode(Node* node, int data)
{
    if (!node) return node;
    if (node->data > data) node->left = DeleteNode(node->left, data);
    else if (node->data < data) node->right = DeleteNode(node->right, data);
    else
    {
        if (!node->right && !node->left) 
        {
            delete node;
            return nullptr;
        }
        Node* temp;
        if (!node->left)
        {
            temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right)
        {
            temp = node->left;
            delete node;
            return temp;
        }
        temp = GetMaxValueNode(node->left);
        node->data = temp->data;
        node->left = DeleteNode(node->left, temp->data);
        return node;
    }
}