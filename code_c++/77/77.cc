class Solution {
public:
    void com(vector<vector<int> > &ret, vector<int> num, vector<int> v, int k)
    {
        if (k == 1) {
            for (int i = 0; i < num.size(); i ++) {
                v.push_back(num[i]);
                ret.push_back(v);
                v.pop_back();
            }
            return ;
        }
        for (int i = num.size() - 1; i >= 0; i --)
        {
            v.push_back(num[num.size() - 1]);
            num.pop_back();
            com(ret, num, v, k - 1);
            v.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        if (k <= 0 || k > n)
            return ret;
        vector<int> num;
        vector<int> v;
        for (int i = n; i > 0; i --)
            num.push_back(i);
        com(ret, num, v, k);
        return ret;
        
    }
};
