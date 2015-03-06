/*
 */
class Solution {
public:

    void combination(vector<vector<int> > &ret, vector<int> &num, vector<int> v,int left, int right, int sum, int target) {

        if (left > right || sum > target)
            return;

        combination(ret, num, v, left + 1, right, sum, target);
        v.push_back(num[left]);

        if (sum + num[left] == target) {
            ret.push_back(v);
            return;
        }
        combination(ret, num, v, left + 1, right, sum + num[left], target);
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<int> v;
        sort(num.begin(), num.end());                   // sort
        int i = 0;
        for (i = 0; i < num.size(); i ++) {             // exclude the elements which are larger than target
            if (num[i] > target)
                break;
        }
        combination(ret, num, v, 0, i - 1, 0, target);
        sort(ret.begin(), ret.end());                  // sort the result and erase the duplicate elements.
        ret.erase(unique(ret.begin(), ret.end()), ret.end());

        return ret;
     }
};
