class LLNode {
public:
	int val;
	LLNode* next;
};

LLNode* reverse(LLNode* node) {
	LLNode* prev = nullptr;
	LLNode* curr = node;
	LLNode* next;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

bool solve(LLNode* node) {
	LLNode* slow = node;
	LLNode* fast = node;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = reverse(slow);
	slow = node;
	while (fast) {
		if (fast->val != slow->val) return false;
		fast = fast->next;
		slow = slow->next;
	}
	return true;
}
