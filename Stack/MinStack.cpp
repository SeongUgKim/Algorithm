#include "stdc++.h"
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    void push(int x) {
        mStack.push(x);
    }
    
    void pop() {
        mStack.pop();
    }
    
    int top() {
        return mStack.top();
    }
    
    int getMin() {
        int min = INT_MAX;
        for (int i = 0; i < mStack.size(); ++i)
        {
            if (mStack.top() < min)
            {
                min = mStack.top();
            }
            mTemp.push(mStack.top());
            mStack.pop();
        }
        for (int i = 0; i < mTemp.size(); ++i)
        {
            mStack.push(mTemp.top());
            mTemp.pop();
        }
        return min;

    }
private:
    stack<int> mStack;
    stack<int> mTemp;
};

int main()
{
    MinStack minstack = new MinStack();
    minstack.push(-1);
    minstack.push(-2);
    minstack.getMin();
    minstack.pop();
    minstack.pop();
    return 0;
}