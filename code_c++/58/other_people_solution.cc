// 1
I've noticed that a lot of solutions use available library functions that return directly the positions of certain characters or do other operations like "split". I personally don't think that's a good idea. Firstly, these functions take some time and usually involve with iteration through the whole string. Secondly, questions like this one is intended to be a practice of detail implementation, not calling other functions. My solution like below uses only the most basic string operations and probably beats many other solutions which call other existing functions.

 int lengthOfLastWord(const char* s) {
        int len = 0;
        while (*s) {
            if (*s++ != ' ')
                ++len;
            else if (*s && *s != ' ')
                len = 0;

        }
        return len;
    }



// 2
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        if (!len) return 0;
        int n=0,  i = len-1;
        while (s[i] == ' ') i--;
        for (; i >= 0; i--,n++)
            if (s[i] == ' ')
                return n;
        return n;
    }
};

