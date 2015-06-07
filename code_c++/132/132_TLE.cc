class Solution {
public:
    bool isPalindrome(string s) {
        int i, j;
        for (i = 0, j = s.size() - 1; i < j; i ++, j --)
            if (s[i] != s[j])
                return false;
        return true;
    }
    int minCut(string s) {
        vector<vector<int> > v(s.size(), vector<int>(s.size(), 0));
        if (isPalindrome(s))
            return 0;
        for (int k = 2; k <= s.size(); k ++ ) {
            for (int i = 0; i < s.size() - k + 1; i ++) {
                int j = i + k - 1;
                if (isPalindrome(s.substr(i, k)))
                    v[i][j] = 0;
                else {
                    int minCut = v[i][i] + v[i + 1][j] + 1; 
                    for (int m = i + 2; m <= j ; m ++) {
                        int temp = v[i][m - 1] + v[m][j] + 1;
                        if (temp < minCut)
                            minCut = temp;
                    }
                    v[i][j] = minCut;
                }
            }
        }
        return v[0][s.size() - 1];
    }
};