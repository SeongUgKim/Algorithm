#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head)
{
    /*int count = 0;
    ListNode* p = head;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    p = head;
    int mid;
    vector<int> left;
    vector<int> right;
    if (count % 2 == 0)
    {
        mid = count / 2;
        for (int i = 0; i < mid; ++i)
        {
            left.push_back(p->val);
            p = p->next;
        }
        for (int i = mid; i < count; ++i)
        {
            right.push_back(p->val);
            p = p->next;
        }
    }
    else 
    {
        mid = count / 2 + 1;
        for (int i = 0; i < mid - 1; ++i)
        {
            left.push_back(p->val);
            p = p->next;
        }
        left.push_back(p->val);
        right.push_back(p->val);
        p = p->next;
        for (int i = mid; i < count; ++i)
        {
            right.push_back(p->val);
            p = p->next;
        }
    }
    if (left.size() != right.size())
    {
        return false;
    }
    int start = 0;
    int end = right.size() - 1;
    while (start < end)
    {
        int temp = right[start];
        right[start] = right[end];
        right[end] = temp;
        start++;
        end--;
    }
    for (int i = 0; i < left.size(); ++i)
    {
        if (left[i] != right[i])
        {
            return false;
        }
    }
    return true;*/
    // with stack
    stack<int> nodeStack;
    ListNode* p = head;
    while (p != nullptr)
    {
        nodeStack.push(p->val);
        p = p->next;
    }
    p = head;
    while (p != nullptr)
    {
        if (p->val != nodeStack.top())
        {
            return false;
        }
        p = p->next;
        nodeStack.pop();
    }
    return true;
    
}
// using vector
bool isPalindrome(ListNode* head) {
    vector<int> list;
    ListNode* temp = head;
    while (temp != nullptr) {
        list.push_back(temp->val);
        temp = temp->next;
    }
    int n = list.size();
    for (int i = 0; i < n; ++i) {
        if (list[i] != list[n - 1 - i]) return false;
    }
    return true;
}

// recursive solution
ListNode* left;
bool helper(ListNode* right) {
    if (!right) return true;
    bool flag = helper(right->next);
    if (!flag) return false;
    if (left->val != right->val) return false;
    left = left->next;
    if (left == right || right->next == left) return true;
    return flag;
}
bool isPalindrome(ListNode* head) {
    left = head;
    ListNode* right = head;
    return helper(right);
}