// 1
This is the standard manual multiplication algorithm. We use two nested for loops, 
working backward from the end of each input number. We pre-allocate our result and 
accumulate our partial result in there. One special case to note is when our carry 
requires us to write to our sum string outside of our for loop.

At the end, we trim any leading zeros, or return 0 if we computed nothing but zeros.

string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }

    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}

// 2
The key part is to use a vector to store all digits REVERSELY. after the calculation, find the rightmost NON-Zero digits and convert it to a string.

class Solution {
public:
    string multiply(string num1, string num2) {

        unsigned int l1=num1.size(),l2=num2.size();
        if (l1==0||l2==0) return "0";

        vector<int> v(l1+l2,0);

        for (unsigned int i=0;i<l1;i++){
            int carry=0;
            int n1=(int)(num1[l1-i-1]-'0');//Calculate from rightmost to left
            for (unsigned int j=0;j<l2;j++){
                int n2=(num2[l2-j-1]-'0');//Calculate from rightmost to left

                int sum=n1*n2+v[i+j]+carry;
                carry=sum/10;
                v[i+j]=sum%10;
            }
            if (carry>0)
                v[i+l2]+=carry;

        }
        int start=l1+l2-1;
        while(v[start]==0) start--;
        if (start==-1) return "0";

        string s="";
        for (int i=start;i>=0;i--)
            s+=(char)(v[i]+'0');
        return s;
    }
};

// 3
See comments inline for explanation.

class Solution {
public:
    string multiply(string num1, string num2) {
        int i, j;
        int m = num1.size(), n = num2.size();
        // max (m + n) digits
        vector<int> product(m + n, 0);
        string result;

        // reverse for ease of calc
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // digit i * digit j contributes to digit i + j
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                product[i + j] += (num1[i] - '0') * (num2[j] - '0');
                product[i + j + 1] += product[i + j] / 10;
                product[i + j] %= 10;
            }
        }

        // remove leading 0; keep last 0 if all 0
        for (i = m + n - 1; i > 0 && 0 == product[i]; i--)
            ;

        for (; i >= 0; i--)
            result += to_string(product[i]);

        return result;
    }
};




