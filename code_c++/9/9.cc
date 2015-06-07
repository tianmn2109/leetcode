/* 算法思想
 * 逆向转换求值
 * 考虑问题：整数溢出，负数返回0
 */
class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = 0;
        int origin = x;
        if (x < 0)
            return false;
            
        while (x != 0) {
            temp = temp * 10 + x%10;
            x = x/10;
        }
        if (x>0 && temp > 0X7FFFFFFFL)
            return false;
            
        if ((int)temp != origin)
            return false;
        
        return true;
    }
};
