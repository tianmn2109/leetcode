/*
 * Kmp algorithm is faster
 */
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int num1 = 0;
        int num2 = 0;
        char *p = haystack;
        while (*p != '\0') {
            p ++;
            num1 ++;
        }
        p = needle;
        while (*p != '\0') {
            p ++;
            num2 ++;
        }
        for (int i = 0; i <= num1 - num2; i ++) {
            int j = 0;
            for (j = 0; j < num2; j ++)
                if (needle[j] != haystack[i + j])
                    break;

            if (j == num2)
                return i;

        }
        return -1;
    }
};
