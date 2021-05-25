class TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
// Brute Force
void helper(vector<int>& vec, vector<int>& nums, int l, int r)
{
    if (r < l)
    {
        return;
    }
    if (r == l)
    {
        vec.push_back(nums[r]);
        return;
    }
    int mid = (r - l) / 2 + l;
    vec.push_back(nums[mid]);
    helper(vec, nums, mid + 1, r);
    helper(vec, nums, l, mid - 1);
}

TreeNode* sortedArrayToBSTBruteForce(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
    {
        return nullptr;
    }
    TreeNode* root = nullptr;
    TreeNode* temp;
    vector<int> vec;
    helper(vec, nums, 0, n - 1);
    for (int i = 0; i < vec.size(); ++i)
    {
        if (root == nullptr)
        {
            root = new TreeNode(vec[i]);
            temp = root;
            continue;
        }
        while (temp != nullptr)
        {
            if (temp->val == vec[i])
            {
                break;
            }
            else if (temp->val > vec[i] && temp->left == nullptr)
            {
                temp->left = new TreeNode(vec[i]);
                break;
            }
            else if (temp->val > vec[i])
            {
                temp = temp->left;
            }
            else if (temp->val < vec[i] && temp->right == nullptr)
            {
                temp->right = new TreeNode(vec[i]);
                break;
            }
            else if (temp->val < vec[i])
            {
                temp = temp->right;
            }
        }
        temp = root;

    }
    return root;
}
// Recursive
TreeNode* helper(vector<int>& nums, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }
    int mid = left + (right - left) / 2;
    TreeNode* current = new TreeNode(nums[mid]);
    current->left = helper(nums, left, mid - 1);
    current->right = helper(nums, mid + 1, right);
    return current;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
    {
        return nullptr;
    }
    return helper(nums, 0, n - 1);
}
