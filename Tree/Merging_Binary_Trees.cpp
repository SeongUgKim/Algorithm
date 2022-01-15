using namespace std;
class Tree {
public:
	int val;
	Tree* left;
	Tree* right;
};
Tree* sum(Tree* node0, Tree* node1) {
    if (node0 == nullptr && node1 == nullptr) return nullptr;
    Tree* node;
    if (node0 == nullptr) {
        node = new Tree(node1->val, node1->left, node1->right);
        return node;
    }
    if (node1 == nullptr) {
        node = new Tree(node0->val, node0->left, node0->right);
        return node;
    }
    node = new Tree();
    node->val = node0->val + node1->val;
    node->left = sum(node0->left, node1->left);
    node->right = sum(node0->right, node1->right);
    return node;
}

Tree* solve(Tree* node0, Tree* node1) {
    if (node0 == nullptr) return node1;
    if (node1 == nullptr) return node0;
    return sum(node0, node1);
}


Tree* solve(Tree* node0, Tree* node1) {
    if (node0 == nullptr) return node1;
    if (node1 == nullptr) return node0;
    node0->val += node1->val;
    node0->left = solve(node0->left, node1->left);
    node0->right = solve(node0->right, node1->right);
    return node0;
}
