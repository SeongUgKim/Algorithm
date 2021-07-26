#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int help(Node* root) {
    if (!root) return 0;
    int n = root->children.size();
    if (n == 0) return 1;
    int max_val = -1;
    for (int i = 0; i < n; ++i) {
        max_val = max(max_val, help(root->children[i]));
    }
    return max_val + 1;
}
int maxDepth(Node* root) {
    return help(root);
}