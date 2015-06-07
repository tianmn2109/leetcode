class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > v;
        vector<int> temp;
        v.push_back(temp);
        if (S.size() == 0)
            return v;
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
        return v;
    }
};
