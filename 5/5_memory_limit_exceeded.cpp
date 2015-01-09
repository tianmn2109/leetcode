i/* 算法思想
  * 动态规划v[i][j]为i到j之间最大回文串
  */
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1)
            return s.size();
            
        int i = 0, j = s.size();
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1)
            return s;
        
        int pos = 0;
        int max = 0;
        int size = s.size();
        vector<vector<int> > v(size,vector<int>(size,0));
        for (int r = 2; r <= s.size(); ++ r) {
            for (int i = 0; i < s.size() - r + 1; i ++) {
                int j = i + r - 1;
                if (s[i] != s[j]) {
                    v[i][j] = v[i][j - 1];
                }
                else {
                    if (isPalindrome(s.substr(i,r))) {
                        max = r;
                        pos = i;
                        v[i][j] = r;
                    }
                    else {
                        v[i][j] = v[i][j - 1];
                    }
                }
            }
        }
        return s.substr(pos,max);
    }
};
