/*
 * 辅助函数：两个字符串的最长公共前缀
 * 然后就字符串数组中的每个值与上一次比较的返回值即前面的最长公共前缀进行比较
*/

class Solution {
public:
    string twoStringCommonPrefix(string &s1, string &s2) {
        if (s1 == "" || s2 == "")
            return "";

        int len = min(s1.size(), s2.size());
        string ret = "";
        for (int i = 0; i < len; i ++)
            if (s1[i] == s2[i])
                ret += s1[i];
            else
                return ret;

       return ret;     //注意 此处必须返回，否则 当for 循环玩 此处次函数就没有返回值了
    }

    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";

        if (strs.size() == 1)
            return strs[0];

        string ret = strs[0];
        for (int i = 1; i < strs.size(); i ++) {
            ret = twoStringCommonPrefix(ret,strs[i]);
        }

        return ret;
    }
};
