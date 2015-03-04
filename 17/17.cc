/*
 * 采用递归思想
 */
class Solution {
public:
    void letters(string digits, vector<string> &dict, string &str, vector<string> &ret) {
        if (digits.size() == 1) {
            for (int i = 0; i < dict[digits[0] - '0'].size(); i ++) {
                str += dict[digits[0] - '0'][i];
                ret.push_back(str);
                str.pop_back();
            }
        }
        else {
            for (int i = 0; i < dict[digits[0] - '0'].size(); i ++) {
                str += dict[digits[0] - '0'][i];
                letters(digits.substr(1), dict, str, ret);
                str.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string str = "";
        vector<string> dict;
        
        if (digits == "")
            return ret;
        
        dict.push_back("");
        dict.push_back("");
        dict.push_back("abc");
        dict.push_back("def");
        dict.push_back("ghi");
        dict.push_back("jkl");
        dict.push_back("mno");
        dict.push_back("pqrs");
        dict.push_back("tuv");
        dict.push_back("wxyz");
        
        letters(digits, dict, str, ret);
        return ret;
    }
};