#include "stdc++.h"
using namespace std;

    string addBinary(string a, string b) {
        int n = a.size() - 1;
        int m = b.size() - 1;
        string s = "";
        int sum = 0;
        int carry = 0;
        while (n >= 0 && m >= 0)
        {
            sum = (a[n--] - '0') + (b[m--] - '0') + carry;
            carry = 0;
            if (sum >= 2)
            {
                carry = 1;
                sum -= 2;
            }
            s += sum + '0';
        }
        if (n < 0)
        {
            while (m >= 0)
            {
                sum = b[m--] - '0' + carry;
                carry = 0;
                if (sum >=2)
                {
                    carry = 1;
                    sum -= 2;
                }
                s += sum + '0';
            }
        }
        else if (m < 0)
        {
            while (n >= 0)
            {
                sum = a[n--] - '0' + carry;
                carry = 0;
                if (sum >= 2)
                {
                    carry = 1;
                    sum -= 2;
                }
                s += sum + '0';
            }
        }
        if (carry == 1)
        {
            s += '1';
        }
        int start = 0;
        int end = s.size() - 1;
        while (start < end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }