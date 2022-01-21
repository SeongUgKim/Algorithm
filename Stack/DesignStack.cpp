using namespace std;
class CustomStack {
public:
    int mMaxSize;
    int mStack[1001] = {0, };
    int mCurrentSize;
    CustomStack(int maxSize) 
        : mMaxSize(maxSize),
          mCurrentSize(0)
    {}
    
    void push(int x) {
        if (mCurrentSize == mMaxSize) return;
        mStack[mCurrentSize++] = x;
        
    }
    
    int pop() {
        if (mCurrentSize == 0) return -1;
        return mStack[--mCurrentSize];
    }
    
    void increment(int k, int val) {
        if (k > mCurrentSize) k = mCurrentSize;
        for (int i = 0; i < k; ++i) {
            mStack[i] += val;
        }
    }
};
