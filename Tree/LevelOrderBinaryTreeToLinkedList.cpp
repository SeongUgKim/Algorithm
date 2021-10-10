#include <vector>
#include <queue>
using namespace std;
class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

class LLNode {
public:
    int val;
    LLNode* next;
};


vector<int> vec;
void bfs(Tree* root) {
    queue<Tree*> q;
    q.push(root);
    while (!q.empty()) {
        Tree* current = q.front();
        Tree* left = current->left;
        Tree* right = current->right;
        if (left) q.push(left);
        if (right) q.push(right);
        vec.push_back(current->val);
        q.pop();
    }
}
LLNode* solve(Tree* root) {
    vec.clear();
    bfs(root);
    LLNode* head = new LLNode();
    head->val = vec[0];
    LLNode* temp = head;
    for (int i = 1; i < vec.size(); ++i) {
        LLNode* n = new LLNode();
        n->val = vec[i];
        temp->next = n;
        temp = temp->next;
    }
    return head;
}