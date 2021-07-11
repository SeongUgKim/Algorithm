#include <string>
using namespace std;
class RunLengthDecodedIterator {
public:
    string mS;
    int mIndex;
    int mLength;
    RunLengthDecodedIterator(string s) {
        mS = "";
        int n = s.size();
        string snum = "";
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') snum += s[i];
            else {
                num = stoi(snum);
                snum = "";
                if (num > 100000) num = 100000;
                for (int j = 0; j < num; ++j) {
                    mS += s[i];
                }
            }
        }
        mIndex = 0;
        mLength = mS.size();
    }
    string next() {
        string res = "";
        return res + mS[mIndex++];
    }

    bool hasnext() {
        return mIndex < mLength;
    }
};