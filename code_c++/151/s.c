#include "string.h"
#include "stdio.h"
#include "stdlib.h"
void reverseAWord(char *s, char *e)
{
    while (s < e) {
        char ch = *s;
        *s = *e;
        *e = ch;
        s ++;
        e --;
    }
}
void reverseWords(char *s) {
    char * p = s;
    char * q = s;
    while (*p != '\0')
    {
        while (*p != '\0' && *p == ' ')
            p ++;
        if (*p == '\0')
            break;
        q = p;
        while (*q != '\0' && *q != ' ')
            q ++;
        q --;
        reverseAWord(p, q);
        p = q + 1;
    }
    p --;
    reverseAWord(s, p);
    p = s;
    char *ss = s;
    while (*p != '\0') {
        while (*p != '\0' && *p == ' ')
            p ++;
        while (*p != '\0' && *p != ' ')
            *(ss ++) = *(p ++);
        *ss = ' ';
    }
    *ss = '\0';
        
    
}

int main()
{
	char s[] = "a";
	reverseWords(s);
	printf("%s\n", s);
	return 0;
}
