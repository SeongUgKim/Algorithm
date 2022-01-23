#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for (int p : pushed) {
            st.push(p);
            while (!st.empty() && j < popped.size() && popped[j] == st.top()) {
                j++;
                st.pop();
            }
        }
        return j == popped.size();
    }
		bool optimized(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        for (int p : pushed) {
            pushed[i++] = p;
            while(i > 0 && pushed[i - 1] == popped[j]) {
                i--; 
                j++;
            }
        }
        return i == 0;
    }
};
