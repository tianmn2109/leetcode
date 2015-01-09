/* 算法思想
 * 从头开始扫描，扫描到当前字符时，将当前字符与之前没重复的字符串进行比较
 * 之前出现，则从出现的位置之后开始算作新的字符串，否则将当前位置加入此字符串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.size() == 0 || s.size() == 1)
            return s.size();
        
        int max = 0;
        int i = 0;
        int j = 1;
        
        while (j < s.size()) {
            for (int k = i; k < j; ++ k) 
                if (s[k] == s[j]) {
                    i = k + 1;
                    break;
                }

            max = (j - i + 1) > max ? (j - i + 1) : max;
            j = j + 1;
        }
        
        return max;       
        
    }
};
