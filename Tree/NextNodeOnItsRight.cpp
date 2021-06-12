#include <vector>
using namespace std;
class Tree
{
public:
	int val;
	Tree* left;
	Tree* right;
};
int order = 0;
void getLevel(Tree* tree, int target, int& level)
{
    if (tree == nullptr)
    {
        return;
    }
    if (tree->val == target)
    {
        order = level;
        return;
    }
    int store = level;
    level = store + 1;
    getLevel(tree->left, target, level);
    level = store + 1;
    getLevel(tree->right, target, level);
}
void help(Tree* tree, int targetLevel, int& level, vector<Tree*>& vec)
{
    if (tree == nullptr)
    {
        return;
    }
    if (level == targetLevel)
    {
        vec.push_back(tree);
        return;
    }
    int store = level;
    level = store + 1;
    help(tree->left, targetLevel, level, vec);
    level = store + 1;
    help(tree->right, targetLevel, level, vec);
}
Tree* solve(Tree* tree, int target) {
    int level = 0;
    getLevel(tree, target, level);
    int targetLevel = order;
    level = 0;
    cout << targetLevel << endl;
    vector<Tree*> vec;
    help(tree, targetLevel, level, vec);
    int i = 0;
    for (; i < vec.size(); ++i)
    {
        if (vec[i]->val == target)
        {
            break;
        }
    }
    for (int j = 0; j < vec.size(); ++j)
    {
        cout << vec[j]->val << endl;
    }
    if (i == vec.size() || i == vec.size() - 1)
    {
        return nullptr;
    }
    return vec[i + 1];
}