// 1 
public class Solution {
public boolean isValid(String s) {
    int c1 = 0, c2 = 0,c3 = 0;

    for (int i = 0; i < s.length(); i ++)
    {
        if (s.charAt(i) == '(')
        {
            if ( (i < s.length() -1) && ( (s.charAt(i+1) == '}') || (s.charAt(i+1) == ']') ) )
            {
                return false;
            }
            c1 ++;
        }
        else if (s.charAt(i) == '[')
        {
            if ( (i < s.length() -1) && ( (s.charAt(i+1) == '}') || (s.charAt(i+1) == ')') ) )
            {
                return false;
            }
            c2 ++;
        }
        else if (s.charAt(i) == '{')
        {
            if ( (i < s.length() -1) && ( (s.charAt(i+1) == ')') || (s.charAt(i+1) == ']') ) )
            {
                return false;
            }
            c3 ++;
        }
        if (s.charAt(i) == ')')
        {
            c1 --;
        }
        else if (s.charAt(i) == ']')
        {
            c2 --;
        }
        else if (s.charAt(i) == '}')
        {
            c3 --;
        }
        if (c1 < 0 || c2 < 0 || c3 < 0)
        {
            return false;
        }
    }

    if (c1 != 0 || c2 != 0 || c3 != 0)
    {
        return false;
    }
    return true;
}


//2   good idea. written in python.
        if s == "":
            return True
        if len(s) % 2 == 1:
            return False

        else:
            while(  "()" in s or "[]" in s or "{}" in s):
                s = s.replace("()", "")
                s = s.replace("[]", "")
                s = s.replace("{}", "")
                return self.isValid(s)
            return False

