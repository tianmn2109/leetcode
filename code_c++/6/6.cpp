/* 算法思想
 *  扫描n/2次， 第一次 余数为0 的加入， 第二次 余数为1 和 n -1 的加入 最后一次余数为n/2的加入
 *  算法效率可以继续提高，通过按照余数 进行跳跃式 扫描
 */
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        
        int num = nRows * 2 - 2;
        string ret = "";
        for (int i = 0; i < s.size(); ++i) {
            if (i % num == 0)
                ret += s[i];
        }
        
        int pre = 1;
        int next = num - 1;
        
        while (pre < next) {
            for (int i = 0; i < s.size(); ++i) {
                if (i % num == pre || i % num == next)
                    ret += s[i];
            }
            pre ++;
            next --;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (i % num == pre)
                ret += s[i];
        }
        return ret;
    }
};
