#include <unordered_set>
#include "stdc++.h"
using namespace std;

vector<string> solve(vector<string>& words)
{
    unordered_set<char> st1 = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
    unordered_set<char> st2 = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
    unordered_set<char> st3 = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
    vector<string> ret;
    for (auto& s : words)
    {
        bool a = true;
        if (st1.count(s[0]))
        {
            for (int i = 1; i < s.size(); ++i)
            {
                if (!st1.count(s[i]))
                {
                    a = false;
                    break;
                }
            }
            if (a == true)
            {
                ret.push_back(s);
            }
        }
        else if (st2.count(s[0]))
        {
            for (int i = 1; i < s.size(); ++i)
            {
                if (!st2.count(s[i]))
                {
                    a = false;
                    break;
                }
            }
            if (a == true)
            {
                ret.push_back(s);
            }
        }
        else if (st3.count(s[0]))
        {
            for (int i = 1; i < s.size(); ++i)
            {
                if (!st3.count(s[i]))
                {
                    a = false;
                    break;
                }
            }
            if (a == true)
            {
                ret.push_back(s);
                cout << s << endl;
            }
        }
    }
    return ret;
}

int main()
{
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    vector<string> ret = solve(words);
    for (auto& s : ret)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}