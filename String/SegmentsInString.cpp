#include "stdc++.h"

using namespace std;

int countSegments(string s)
{
    /*stringstream ss(s);
    string token;
    vector<string> result;
    while (ss >> token) 
    {
        result.push_back(token);
    }*/
    /*stringstream ss(s);
    string token;
    vector<int> result;
    while (getline(ss, token, " ")) 
    {
        result.push_back(token);
    }
    return result.size();*/
    if (s == "") {
        return 0;
    }
    int c = 0;
    for (int i = 0; i < s.length(); ++i) {
        if ((s[i] != ' ') && (s[i + 1] == ' ' || s[i + 1] == '\0'))
        {
            c++;
        }
    }
    return c;
}

int main()
{
    string s = "love live! mu'sic forever";
    cout << countSegments(s) << endl;
}