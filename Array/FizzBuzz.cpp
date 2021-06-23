#include "stdc++.h"
using namespace std;

vector<string> solve(int n)
{
    vector<string> ret;
    ret.resize(n);
    for (int i = 0; i < ret.size(); ++i)
    {
        string s = "";
        int temp = i + 1;
        if (temp % 3 == 0 && temp % 5 == 0)
        {
            s += "FizzBuzz";
            ret[i] = s;
            continue;
        }
        if (temp % 3 == 0)
        {
            s += "Fizz";
            ret[i] = s;
            continue;
        }
        if (temp % 5 == 0)
        {
            s += "Buzz";
            ret[i] = s;
            continue;
        }
        s += to_string(temp);
        ret[i] = s;
    }
    return ret;
}

int main()
{
    vector<string> ans = solve(15);
    for (string s : ans)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}