class Solution {
public:
    int strToBits(string s) {
        int ret = 0;
        for (int i = 0; i < 10; i ++) {
            if (s[i] == 'A') {
                continue;
            }
            else if (s[i] == 'C') {
                ret |= 1 << (i * 2);
            }
            else if (s[i] == 'G') {
                ret |= 2 << (i * 2);
            }
            else {
                ret |= 3 << (i * 2);
            }
        }
        return ret;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> r;
;
        map<int, int> m;
        int count = 0;
        for (int i = 0; i < (int)s.size() - 10 + 1; i ++) {
            string str = s.substr(i, 10);
            int temp = strToBits(str);
            if (m.find(temp) == m.end()) {
                m[temp] = 1;
            }
            else {
                if (m[temp] == 1) {
                    r.push_back(str); 
                    count ++;
                }
                m[temp] ++;
            }
        }
     //   r.resize(count);
        return r;
    }
};
