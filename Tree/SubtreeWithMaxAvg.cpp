class Tree {
public:
    int val;
    Tree* left;
    Tree* right;
};

 // S(x) -> subtree x에 있는 모든 노드들의 합
 // N(x) -> subtree x에 있는 모든 노드개수

 // S(x) = x->val + S(x->left) + S(x->right); S(null) = 0
 // N(x) = 1 + N(x->left) + N(x->right); N(null) = 0

 // Avg(x) = S(x) / N(x) Avg(null) = S(null) / N(null)
double maxAvg;
pair<double, double> help(Tree* root)
{
    if (root == nullptr)
    {
        return make_pair(0, 0);
    }
    pair<double, double> temp1 = help(root->left);
    pair<double, double> temp2 = help(root->right);
    double sum = root->val + temp1.first + temp2.first;
    double count = 1 + temp1.second + temp2.second;
    double avg = sum / count;
    maxAvg = max(maxAvg, avg);
    return make_pair(sum, count);
}
double solve(Tree* root) {
    if (root == nullptr)
    {
        return 0;
    }
    maxAvg = DBL_MIN;
    pair<double, double> res = help(root);
    return maxAvg;
}
