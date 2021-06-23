#include "stdc++.h"
using namespace std;

string solve (string sentence)
{
    if (sentence.size() == 0)
    {
        return "";
    }
    vector<string> temp;
    stringstream ss(sentence);
    string token;
    while (ss >> token)
    {
        temp.push_back(token);
    }
    string ret = "";
    for (int i = temp.size() - 1; i > 0; --i)
    {
        ret += temp[i] + " ";

    }
    ret += temp[0];
    return ret;
    
}

int main()
{
    string sentence = "hello there my friend";
    cout << solve(sentence) << endl;
}