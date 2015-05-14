class Solution {
public:
    int numDecodings(string s) {
       if (s.size() == 0)
            return 0;
       vector<int> dp(s.size());
       dp[0] = 0;
       
       for (int i = 0; i < s.size(); i ++) {
           dp[i] = 0;
           if (i >= 1) {
               string temp = s.substr(i - 1, 2);
               if (temp >= "10" && temp <= "26")
                    if (i > 1)
                        dp[i] += dp[i - 2];
                    else
                        dp[i] += 1;
               if (s[i] >= '1' && s[i] <= '9')
                    dp[i] += dp[i - 1];
           }
           else {
               dp[i] = (s[i] >= '1' && s[i] <= '9');
           }
       }
       return dp[s.size() - 1];
    }
};