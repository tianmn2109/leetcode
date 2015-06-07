class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() == 0 || T.size() == 0)
            return 0;
        int request[256] = {0};
        bool need[256] = {false};
        for (int i = 0; i < T.size(); i ++) {
            request[T[i]] ++;
            need[T[i]] = true;
        }
        int count = T.size();
        int i = -1, j = 0;
        int minWindow = 0x7fffffff;
        int startIndex = -1;
        while (i < (int)S.size() && j < S.size()) {
            if (count == 0) {
                if (i - j + 1 < minWindow) {
                    minWindow = i - j + 1;
                    startIndex = j;
                }
                request[S[j]] ++;
                if (request[S[j]] > 0 && need[S[i]] == true)
                    count ++;
                j ++;
            }
            else {
                i ++;
                request[S[i]] --;
                if (request[S[i]] >= 0 && need[S[i]] == true)
                    count --;
            }
        }
        return startIndex == -1 ? "" : S.substr(startIndex, minWindow);
    }
};
