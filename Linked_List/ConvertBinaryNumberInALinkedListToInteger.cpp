class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode();
};

int getDecimalValue(ListNode* head) {
    vector<int> v;
    ListNode* temp = head;
    while (temp != nullptr)
    {
        v.push_back(temp->val);
        temp = temp->next;
    }
    int n = v.size();
    int res = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        res += pow(2, j++) * v[i];
    }
    return res;
}