#include "stdc++.h"
using namespace std;
vector<string> solve(int n) {
   vector<string> a(n, "");
   for (int i = 1; i <= n; ++i)
   {
       if (i % 3 == 0)
       {
           a[i - 1] = "clap";
           continue;
       }
       string s = to_string(i);
       for (int j = 0; j < s.size(); ++j)
       {
           if (s[j] == '3' || s[j] == '6' || s[j] == '9')
           {
               a[i - 1] = "clap";
               break;
           }
       }
       if (a[i - 1] == "")
       {
           a[i - 1] = to_string(i);
       }
   }
   return a; 
}