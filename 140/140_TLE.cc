class Solution {
public:
    vector<bool> *dp;
    vector<string> str;
    vector<string> res;
    void breakWord(string s, int i) {
        if (i == -1) {
            string temp = "";
            for (int k = str.size() - 1; k >= 0; k --) {
                temp += str[k];
                if (k > 0)
                    temp += " ";
            }
            res.push_back(temp);
            return ;
        }
        else {
            for (int k = 0; k <= i; k ++) {
                if (dp[k][i - k]) {
                    str.push_back(s.substr(k, i - k + 1));
                    breakWord(s, k - 1);
                    str.pop_back();
                }
            }
            return ;
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        dp = new vector<bool>[len];
        for (int i = 0; i < len; i ++)
            for (int j = i; j < len; j ++) {
                if (wordDict.find(s.substr(i, j- i + 1)) != wordDict.end())
                    dp[i].push_back(true);
                else
                    dp[i].push_back(false);
            }
        breakWord(s, s.size() - 1);
        return res;
        
    }
};