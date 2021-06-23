#include "stdc++.h"
using namespace std;
int solve(string s) {
    /*string result = "";
    stack<char> parentheses;
    for (char c : s) 
    {
        if (c == '(')
        {
            parentheses.push('(');
        }
        else if (c == ')')
        {
            if (!parentheses.empty())
            {
                char p = parentheses.top();

                result += p;
                result += ')';
                parentheses.pop();
            }
        }
    }
    return result.size();*/
    int total = 0;
    int var = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            var++;
        }
        else if (var == 0)
        {
            continue;
        }
        else 
        {
            var--;
            total++;
        }
    }
    return total * 2;
}