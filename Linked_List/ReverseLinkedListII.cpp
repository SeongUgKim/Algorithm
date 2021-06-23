#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseBetween(ListNode* head, int left, int right) {
    stack<int> st;
    ListNode* temp = head;
    int count = 1;
    while (temp != nullptr) {
        if (count < left) {
            count++;
            temp = temp->next;
            continue;
        }
        if (count > right) break;
        st.push(temp->val);
        temp = temp->next;
        count++;
    }
    count = 1;
    temp = head;
    while (temp != nullptr) {
        if (count < left) {
            temp = temp->next;
            count++;
            continue;
        }
        if (count > right) break;
        temp->val = st.top();
        st.pop();
        temp = temp->next;
        count++;
    }
    return head;
}