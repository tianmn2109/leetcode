// 1
We can construct the following string and run KMP algorithm on it: (s) + (some symbol not present in s) + (reversed string)

After running KMP on that string as result we get a vector p with values of a prefix function for each character (for definition of a prefix function see KMP algorithm description). We are only interested in the last value because it shows us the largest suffix of the reversed string that matches the prefix of the original string. So basically all we left to do is to add the first k characters of the reversed string to the original string, where k is a difference between original string size and the prefix function for the last character of a constructed string.

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};


// 2  important feel better than mine.
The key idea is to first reverse the string, then check the max length from n to 0

class Solution {
public:
    string shortestPalindrome(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size(),l;
        for(l=n;l>=0;l--)
        {
            if(s.substr(0,l)==s2.substr(n-l))
                break;
        }
        return s2.substr(0,n-l)+s;
    }
};

// 3
The brute-force method is O(N^2),which gets TLE. So have to move to Manacher's algorithm, which is O(N) time. Such algorithm returns the maximum length of the palindrome string centered at i, so we just need to find the maximum length palindrome string with the left end point at 0. Then we can construct the result. The Manacher's algorithm codes are partially copied from this site.

class Solution {
public:
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret(2*n+3, '#');
  ret[0] = '^';ret[2*n+1] = '$';
  for (int i = 1; i <= n; i++)  ret[2*i]=s[i-1];

  return ret;
}

string shortestPalindrome(string s) {

  int len = s.size();
  if(len<=1) return s;
  string T = preProcess(s);
  const int n = T.length();
  int P[n], i_mirror;
  int C = 0, R = 0;

  for (int i = 1; i < n-1; i++) {
    i_mirror = 2*C-i; // equals to i' = C - (i-C)

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;

    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Just changed this part, 
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (1==i-P[i]) maxLen = P[i];
  }
  string temp = s.substr(maxLen);
  reverse(temp.begin(),temp.end());
  return temp+s;

    }
};
Also KMP based method added, where T is an array to save the maximum length of the Palindrome substring ending at res[i].

class Solution { public: string shortestPalindrome(string s) { const int len = s.size(); string res = s; if(len>1) { reverse(res.begin(), res.end()); res = s + '&' + res;

       int i, T[2*len+1];
       T[0] = 0;

       for(i=1; i<=2*len; i++)
       {
           T[i] = T[i-1];
           while(T[i]>0 && res[i]!=res[T[i]]) T[i] = T[T[i]-1];
           T[i] += (res[i] ==res[T[i]]);
       }

       return res.substr(len+1,len-T[2*len]) + s;
   }
   return s;
}
};
