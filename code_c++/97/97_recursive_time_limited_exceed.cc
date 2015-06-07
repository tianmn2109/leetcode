class Solution {
public:
    bool isil(string &s1, string &s2, string &s3, int n1, int n2, int n3) {
        if (n1 + n2 != n3)
            return false;
        if (n1 == 0 && n2 == 0 && n3 == 0)
            return true;
        if (s1[n1 - 1] != s3[n3 - 1] && s2[n2 - 1] != s3[n3 - 1])
            return false;
        if (s1[n1 - 1] == s3[n3 - 1] && s2[n2 - 1] != s3[n3 - 1])
            return isil(s1, s2, s3, n1 - 1, n2, n3 - 1);
        if (s1[n1 - 1] != s3[n3 - 1] && s2[n2 - 1] == s3[n3 - 1])
            return isil(s1, s2, s3, n1, n2 - 1, n3 - 1);
        return isil(s1, s2, s3, n1, n2 - 1, n3 - 1) || isil(s1, s2, s3, n1 - 1, n2, n3 - 1);
    }
    bool isInterleave(string s1, string s2, string s3) {
        return isil(s1, s2, s3, s1.size(), s2.size(), s3.size());
    }
};
