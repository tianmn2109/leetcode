// 1
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string tmp;
        long long total=1;
        for(int i=1;i<=n;i++)
        {
            tmp+=(i+'0');
            total *= i;
        }
       // k = k%total;
        int start,left;
        long long a=total;
        for(int i=n;i>0;i--)
        {
             a = a/i;
            start = (k-1)/a;
            left = k-start*a;
            char ch = tmp[start];
            res+=ch;
            tmp.erase(start,1);
            k = left;
        }
        //res += tmp[1];
        return res;
    }
};

