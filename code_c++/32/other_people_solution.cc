// 1 
Since any valid parentheses sequence starts from a '(' and ends at ')', we can calculate new length when we meet a ')'. The key is to use a stack to store all the indices and the start position is always the one on top of the stack. See the code below for details.

 // Using a stack. One pass
    int longestValidParentheses(string s) {
        vector<int> stack;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                stack.push_back(i);
            else {
                if (!stack.empty() && s[stack.back()] == '(') {
                    stack.pop_back();
                    int lastPos = -1;
                    if (!stack.empty())
                        lastPos = stack.back();
                    int curLen = i - lastPos;
                    maxLen = (maxLen < curLen) ? curLen : maxLen;
                } else
                    stack.push_back(i);
            }
        }
        return maxLen;
    }



// 2
class LVP{

    public:
    int lvp( string s ){
        int len = s.size();
        if( !len )          // if string is empty, return 0 instantly.
            return 0;
        for( int i = 0;i < len;i++ )    
            if( s[i] == ')' )   
                for( int j = i - 1;j >= 0;j-- )     // for every ')’，find the first match '(' before it
                    if( s[j] == '(' )   {           // and mark the two with a special flag,like '0'
                        s[i] = '0';
                        s[j] = '0';
                        break;
                    }
        int max = 0,temp = 0;                       
        for( int i = 0;i < len;i++ )    {           // the problem changed to find the longest '0' in the string
            if( s[i] == '0' )
                temp++;
            else    {
                max = temp > max ? temp : max;
                temp = 0;
            }
        }
        max = temp > max ? temp : max;              // longest '0'sequence may still stored in temp
        return max;
    }
};


// 3 Dp
   int longestValidParentheses(string s) {
        int cnt = 0; // count of "("
        vector<int> dp(s.size()+1, 0);

        for (size_t i = 1; i <= s.size(); i++) {
            if (s[i-1] == '(') {
                cnt++;
            } else {
                if (cnt > 0) {  // there exists an unclosed "(" to match ")"
                    cnt--;
                    dp[i] = 2;
                    if (s[i-2] == ')')  // add the length of previous closed ")" neighbor
                        dp[i] += dp[i-1];                        
                    dp[i] += dp[i-dp[i]]; // add the length of previous valid parentheses
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

// 4
My solution uses DP. The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i.
And the DP idea is :
If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.
Else if s[i] is ')'
     If s[i-1] is '(', longest[i] = longest[i-2] + 2
     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.

   int longestValidParentheses(string s) {
            if(s.length() <= 1) return 0;
            int curMax = 0;
            vector<int> longest(s.size(),0);
            for(int i=1; i < s.length(); i++){
                if(s[i] == ')'){
                    if(s[i-1] == '('){
                        longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                        curMax = max(longest[i],curMax);
                    }
                    else{ // if s[i-1] == ')', combine the previous length.
                        if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                            curMax = max(longest[i],curMax);
                        }
                    }
                }
                //else if s[i] == '(', skip it, because longest[i] must be 0
            }
            return curMax;
        }


Updated: thanks to Philip0116, I have a more concise solution(though this is not as readable as the above one, but concise):

int longestValidParentheses(string s) {
        if(s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++){
            if(s[i] == ')' && i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
                    longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                    curMax = max(longest[i],curMax);
            }
        }
        return curMax;
    }

