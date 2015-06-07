class Solution {

public:

    int lengthOfLastWord(const char *s) {

        int i = 0;

        while (s[i] != '\0')

            i ++;

        i --;

        int count = 0;

        while (i >= 0 && s[i] == ' ')

            i --;

        if (i < 0)

            return 0;

        while (i >= 0 && (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')) {

            count ++;

            i --;

        }

            

        return count;

    }

};
