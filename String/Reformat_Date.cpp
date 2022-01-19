#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> month;
        month["Jan"] = "01";
        month["Feb"] = "02";
        month["Mar"] = "03";
        month["Apr"] = "04";
        month["May"] = "05";
        month["Jun"] = "06";
        month["Jul"] = "07";
        month["Aug"] = "08";
        month["Sep"] = "09";
        month["Oct"] = "10";
        month["Nov"] = "11";
        month["Dec"] = "12";
        int n = date.size();
        string day = "";
        char first = date[0];
        char second = date[1];
        if (second >= '0' && second <= '9') {
            day += first;
            day += second;
        } else {
            day += '0';
            day += first;
        }
        int i = 4;
        if (date[i] == ' ') i++;
        string mon_s = "";
        for (int j = 0; j < 3; ++j) {
            mon_s += date[i + j];
        }
        string mon = month[mon_s];
        while (date[i] != ' ') {
            i++;
        }
        i++;
        string years_s = "";
        for (int j = 0; j < 4; ++j) {
            years_s += date[i + j];
        }
        string res = "";
        res += years_s;
        res += "-";
        res += mon;
        res += "-";
        res += day;
        return res;
    }
};
