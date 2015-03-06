/*
 * recursicve method;      ***************  important
 */
class Solution {
public:
    void combination(vector<vector<int> > &ret, vector<int> &candidates, int left, int right, vector<int> v, int sum, int target) {
       if (left > right || sum > target)
           return;

       combination(ret, candidates, left + 1, right, v, sum, target);
       v.push_back(candidates[left]);
       if (sum + candidates[left] == target) {
           ret.push_back(v);
           return;
       }
       combination(ret, candidates, left, right, v, sum + candidates[left], target);
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int> v;
        int sum = 0;

        int i = candidates.size() - 1;
        sort(candidates.begin(), candidates.end());
        combination(ret, candidates, 0, i, v, sum, target);
        sort(ret.begin(), ret.end());

        return ret;
    }
};
