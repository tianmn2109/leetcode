class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > v;
        vector<int> temp;
        v.push_back(temp);
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); i ++) {
            int len = v.size();
            temp.clear();
            for (int j = 0; j < len; j ++) {
                if (v[j].size() != 0)
                    temp = v[j];
                temp.push_back(S[i]);
                v.push_back(temp);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }
};
