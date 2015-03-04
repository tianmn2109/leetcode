/*
 * @param left: 左括号个数
 * @param right: 右括号个数
 */
class Solution {
public:
    void generate(vector<string> &ret, string str, int left, int right) {
        if (left > right)
            return;
        if (left < 0 || right < 0)
            return;
        if (left == 0 && right == 0)
        {
            ret.push_back(str);
            return;
        }
        else {
            generate(ret, str + '(', left - 1, right); //此处不能用left -- ，如果是left -- 传入的还是left的值，而不是left - 1的值
            generate(ret, str + ')', left, right - 1); //同上 right - 1
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string str = "";
        int left = n;
        int right = n;
        generate(ret, str, left, right);
        return ret;
    }
};
