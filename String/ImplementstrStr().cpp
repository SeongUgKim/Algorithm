#include "stdc++.h"
using namespace std;

    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
        {
            return 0;
        }
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        bool isComplete = false;
        int index = 0;
        int start = 0;
        int n = 0;
        while (n < needle.size() && index < haystack.size())
        {
            if (haystack[index] == needle[n])
            {
                index++;
                n++;
            }
            else 
            {
                index = start + 1;
                while (haystack[index] != needle[0])
                    
                {
                    index++;
                    if (index == haystack.size())
                    {
                        return -1;
                    }
                }
                n = 0;
                start = index;
            }
            if (n == needle.size())
            {
                isComplete = true;
            }
        }
        if (isComplete == true)
        {
            return start;
        }
        return -1;
    }