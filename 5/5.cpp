/* 算法思想： 最笨的算法，这次竟然不是想到的第一种解决方案，以后要先想简单的方法
 * 扫字符串中每个元素
 * 每个元素 按照三种不同的可能形成回文串的方式去扫描
 */
class Solution {
public:

    string longestPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1)
            return s;
        vector<int> v(s.size(),1);
        int max = 1;
        int pos = 0;
        for (int i = 0; i < s.size(); ++ i) {
            int start = i;
            int end = i;
            while (start >= 0 && end <s.size() && s[start] == s[end]) {
                start --;
                end ++;
            }
            int temp = end - start - 1;
            max = temp > max ? (pos = i - temp/2,temp) : max;
            v[i] = temp > v[i] ? temp : v[i];
            
            start = i - 1;
            end = i;
            while (start >= 0 && end <s.size() && s[start] == s[end]) {
                start --;
                end ++;
            }
            temp = end - start - 1;
            max = temp > max ? (pos = i - temp/2,temp) : max;
            v[i] = temp > v[i] ? temp : v[i];
            
            start = i;
            end = i + 1;
            while (start >= 0 && end <s.size() && s[start] == s[end]) {
                start --;
                end ++;
            }
            temp = end - start - 1;
            max = temp > max ? (pos = i - temp/2 + 1,temp) : max;
            v[i] = temp > v[i] ? temp : v[i];
            
            
        }

