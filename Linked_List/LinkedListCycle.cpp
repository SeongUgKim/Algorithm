#include <unordered_set>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> st;
    ListNode* temp = head;
    while (temp != nullptr)
    {
        if (st.count(temp))
        {
            return true;
        }
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}

bool solve(ListNode* head)
{
    if (head == nullptr)
    {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}