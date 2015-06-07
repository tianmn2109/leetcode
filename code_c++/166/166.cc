class Solution {
public:
    string fractionToDecimal(int nume, int deno) {
        string strInter = "";
        string strFrac = "";
        long long numerator = (long long)nume;
        long long denominator = (long long)deno;
        bool isNegative = ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) ? true : false;
        numerator = numerator < 0 ? -numerator : numerator;
        denominator = denominator < 0 ? -denominator : denominator;
        long long nInter = numerator / denominator;
        long long nFrac = numerator % denominator;
        if (nInter == 0)
            strInter = "0";
        else {
            while (nInter) {
                char ch = nInter % 10 + '0';
                strInter += ch;
                nInter /= 10;
            }
        }
        if (isNegative)
                strInter += "-";
            reverse(strInter.begin(), strInter.end());
        if (nFrac == 0)
            return strInter;
        strFrac += ".";
        long long cur = nFrac;
        map<int, int> m;
        long i = 1;
        m[cur] = i;
        while (cur) {
            char ch = '0' + cur * 10 / denominator;
            strFrac = strFrac + ch;
            cur = cur * 10 % denominator;
            if (m.find(cur) != m.end()) {
                strFrac.insert(m[cur], "(");
                strFrac += ")";
                break;
            }
            m[cur] = ++ i;
        }
        return strInter + strFrac;
    }
};
