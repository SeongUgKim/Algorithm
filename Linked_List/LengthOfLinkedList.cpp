#include "stdc++.h"
using namespace std;

class LLNode {
    public:
        int val;
        LLNode *next;
 };

 int solve(LLNode* node)
 {
    /*LLNode* p = node; //iterate all list
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;*/
    //recursive
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + solve(node->next);
 }

 int main()
 {
    return 0;
 }