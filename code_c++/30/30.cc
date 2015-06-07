class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if (words.size() == 0)
            return ret;
        int wordLen = words[0].size();
        int wordNum = words.size();
        map<string, int> mapWords;
        map<string, int> mapCount;
        for (vector<string>::iterator it = words.begin(); it != words.end(); it ++)
            ++ mapWords[*it];
        for (int i = 0; i < s.size() - wordLen * wordNum + 1; i ++) {
            mapCount.clear();
            int j = 0;
            for (j = 0; j < wordNum; j ++) {
                string str = s.substr(i + j * wordLen, wordLen);
                if (mapWords.find(str) != mapWords.end()) {
                    ++ mapCount[str];
                    if (mapCount[str] > mapWords[str])
                        break;
                }
                else
                    break;
            }
            if (j == wordNum)
                ret.push_back(i);
        }
        return ret;
    }
};
