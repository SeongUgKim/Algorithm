#include "stdc++.h"
using namespace std;

    string longestCommonPrefix(vector<string>& strs) {
        // horizontal scanning
        if (strs.size() == 0)
        {
            return "";
        }
        vector<char> a;
        for (int i = 0; i < strs[0].size(); ++i)
        {
            a.push_back(strs[0][i]);
        }
        int check = 0;
        int end = a.size() - 1;
        for (int i = 1; i < strs.size(); ++i)
        {
            check = 0;
            while (check < end + 1 && check <strs[i].size())
            {
                if (a[check] == strs[i][check])
                {
                    check++;
                    continue;
                }
                break;
            }
            end = check - 1;
        }
        string s = "";
        for (int i = 0; i <= end; ++i)
        {
            s += a[i];
        }
        return s;
        // Sorting and compare first and last
        if (strs.size() == 0)
        {
            return "";
        }
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[strs.size() - 1];
        int i = 0;
        for (; i < a.size() && i < b.size(); ++i)
        {
            if (a[i] != b[i])
            {
                break;   
            }
        }
        string ret = "";
        for(int j = 0; j < i; ++j)
        {
            ret += a[j];
        }
        return ret;
        // vertical scanning
        /*
                string ret = "";
        if (strs.size() == 0)
        {
            return ret;
        }
        
        int index = 0;
        for (char c : strs[0])
        {
            for (int i = 1; i < strs.size(); ++i)
            {
                if (index >= strs[i].size() || strs[i][index] != c)
                {
                    return strs[i].substr(0, index);
                }
            }
            ret += c;
            index++;
        }
        return ret;
        */
    }