#include <string>
using namespace std;
bool solve(string s0, string s1) {
   if (s0.size() != s1.size()) return false;
   s1 = s1 + s1;
   return s1.find(s0) != string::npos;
}