/*算法思想：考虑的多种情况
 *1: 字符串前面有多个空格等空白字符
 *2：第一个非空白字符为+或者-
 *3：字符串中间有非数字字符，则只转换前面的字符
 *4：数值溢出32 64 都可能溢出，64位最大值19位数 用count记录转换后的数的位数
 */
class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL)
            return 0;
            
        long long temp = 0;
        bool isNegative = false;
        
        while (*str == ' ')//空白字符
            str ++;
        
        if (*str == '-' || *str == '+') {//加号或者减号
            if (*str == '-')
                isNegative = true;
            str ++;
        }
        int count = 0;
        while (*str != '\0') {
            if (*str < '0' || *str > '9')
                break;
            temp = temp * 10 + *str - '0';
            str ++;
            count ++;                  //记录转换后的数字的位数，判断是否64位数溢出
        }
        if (count > 18)
            return isNegative ? 0X80000000 : 0X7FFFFFFF;
        if (isNegative)
            temp = -temp;
        if (temp > 0X7FFFFFFF)
            return 0X7FFFFFFF;
        if  (temp < -(0X7FFFFFFFL + 1))
            return 0X80000000;
        return (int)temp;
    }
};
