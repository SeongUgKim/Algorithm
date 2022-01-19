#include <unordered_map>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       	ListNode* a = headA;
	ListNode* b = headB;
	ListNode* ans = nullptr;
	while (a) {
		a->val *= -1;
		a = a->next;
	}
	while (b) {
		if (b->val < 0) {
			ans = b;
			break;
		}
		b = b->next;
	}
	a = headA;
	while (a) {
		a->val *= -1;
		a = a->next;
	}
	return ans;
}
	       
