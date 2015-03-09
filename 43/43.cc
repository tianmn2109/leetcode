/*
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string add(string num1, string num2) {
        if (num1.size() == 0)
            return num2;
        if (num2.size() == 0)
            return num1;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string strRet = "";
        int over = 0;
        int len = (num1.size() > num2.size()) ? num2.size() : num1.size();

        int i = 0;
        for (i = 0; i < len; i ++) {
            int sum = (int)(num1[i] - '0') + (int)(num2[i] - '0') + over;
            char ch = sum % 10 + '0';
            strRet = strRet + ch;
            over = sum / 10;
        }

        for (; i < num1.size(); i ++) {
            int sum = (int)(num1[i] - '0') + over;
            char ch = sum % 10 + '0';
            strRet = strRet + ch;
            over = sum / 10;
        }

        for (; i < num2.size(); i ++) {
            int sum = (int)(num2[i] - '0') + over;
            char ch = sum % 10 + '0';
            strRet = strRet + ch;
            over = sum / 10;
        }

        if (over)
            strRet += "1";
        reverse(strRet.begin(), strRet.end());
        return strRet;
    }

    string mul(string num1, int num2, int zero) { // num is multiple number, num2 is an single number, and zero is the num of '0' to add at the end.
        string str = "0";
        if (num2 == 0)
            return "0";
        if (num1 == "0")
		return "0";
        
        for (int i = 0; i < num2; i ++)
            str = add(str,num1);

        for (int i = 0; i < zero; i ++)
           str += "0";
       return str;
    }

    string multiply(string num1, string num2) {

        string ret = "0";

        for (int i = num2.size() - 1; i >= 0; i --) {
            string temp = mul(num1, num2[i] - '0', num2.size() - 1 - i);
            ret = add(ret, temp);
        }
        return ret;
    }
};

int main() 
{
        Solution s;
        cout << s.multiply("0", "52") << endl;

	return 0;
}
