class Solution {
public:
        static bool cmp(const string &s1, const string &s2) {
            return (s1 + s2) > (s2 + s1);
        }
    string intToStr(int num) {
        if (num == 0)
            return "0";
        string ret = "";
        while (num) {
            char ch = num % 10 + '0';
            ret = ret + ch;
            num = num / 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    } 
    string largestNumber(vector<int> &num) {
        vector<string> strLargestNum;
        for (int i = 0; i < num.size(); i ++) {
            strLargestNum.push_back(to_string(num[i]));
        }
        sort(strLargestNum.begin(), strLargestNum.end(), cmp);
        string ret = "";
        for (int i = 0; i < strLargestNum.size(); i ++)
                ret += strLargestNum[i];
        if (ret[0] == '0')
            return "0";
        return ret;
    }
};
