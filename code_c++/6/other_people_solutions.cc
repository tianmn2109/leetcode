// 1 O(n)  perfect

string convert(string s, int nRows) {

    if (nRows <= 1)
        return s;

    const int len = (int)s.length();
    string *str = new string[nRows];

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);

        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;

        row += step;
    }

    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }

    delete[] str;
    return s;
}


// 2 transverse each character only once

public class Solution {
    public String convert(String s, int nRows) {
        if (nRows == 1)
            return s;
        StringBuilder strBuilder = new StringBuilder();
        int borderRowStep = 2 * nRows - 2;
        for (int i = 0; i < nRows; i++) {
            if (i == 0 || i == nRows - 1) {
                for (int j = i; j < s.length(); j = j + borderRowStep) {
                    strBuilder.append(s.charAt(j));
                }
            } else {
                int j = i;
                boolean flag = true;
                int insideRowLargeStep = 2 * (nRows - 1 - i);
                int insideRowSmallStep = borderRowStep - insideRowLargeStep;
                while (j < s.length()) {
                   strBuilder.append(s.charAt(j));
                    if (flag)
                        j = j + insideRowLargeStep;
                    else
                        j = j + insideRowSmallStep;
                    flag = !flag;
                }
            }
        }
        return strBuilder.toString();

}
}


// 3 similar to 1

class Solution{
public String convert(String s, int nRows) {
    char[] c = s.toCharArray();
    int len = c.length;
    StringBuffer[] sb = new StringBuffer[nRows];
    for (int z=0; z < sb.length; z++) sb[z] = new StringBuffer();
    int k=0;
    while (k < len) {
        for (int zigZagIndex = 0; zigZagIndex < nRows && k < len; zigZagIndex++) // vertically down
            sb[zigZagIndex].append(c[k++]);
        for (int zigZagIndex = nRows-2; zigZagIndex >= 1 && k < len; zigZagIndex--) // obliquely up
            sb[zigZagIndex].append(c[k++]);
    }
    for (int index = 1; index < sb.length; index++)
        sb[0].append(sb[index]);
    return sb[0].toString();
}
}
