class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        int dis = 1;
        int count = 1;
        if (start == "" || end == "" || dict.size() == 0)
            return 0;
        q.push(start);
        dict.erase(start);
        while (!dict.empty() && !q.empty()) {
            string s = q.front();
            q.pop();
            count --;
            for (int i = 0; i < s.size(); i ++) {
                char ch = s[i];
                for (int j = 'a'; j <= 'z'; j ++) {
                    s[i] = j;
                    if (s == end)
                        return dis + 1;
                    if (dict.find(s) != dict.end()) {
                        q.push(s);
                        dict.erase(s);
                    }
                }
                s[i] = ch;
            }
            if (count == 0) {
                dis ++;
                count = q.size();
            }
        }
        return 0;
    }
};
