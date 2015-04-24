class Solution {
public:
    void findValidIp(string s, string strIp, vector<string> &v, int num) {
        if (num == 4) {
            if (s.size() > 3)
                return ;
            if (s.size() > 1 && s[0] == '0')
                return ;
            if (atoi(s.c_str()) > 255)
                return ;
            strIp += s;
            v.push_back(strIp);
            return ;
        }
        if (s.size() < 5 - num)
            return ;
        string tempIp = strIp;
        if (s.size() >= 5 - num ) {
            strIp = strIp + s.substr(0, 1) + ".";
            findValidIp(s.substr(1), strIp, v, num + 1);
        }
        strIp = tempIp;
        if (s.size() >= 6 - num && s[0] != '0') {
            strIp = strIp + s.substr(0, 2) + ".";
            findValidIp(s.substr(2), strIp, v, num + 1);
        }
        strIp = tempIp;
        if (s.size() >= 7 - num && s[0] != '0') {
            if (atoi(s.substr(0, 3).c_str()) > 255)
                return ;
            strIp = strIp + s.substr(0, 3) + ".";
            findValidIp(s.substr(3), strIp, v, num + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        string strIp = "";
        findValidIp(s, strIp, v, 1);
        return v;
    }
};
