class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        map<int,int> m;
        for (int i = 0; i < numbers.size(); ++ i) {
            if (m.count(target - numbers[i])) {
                int n = m[target - numbers[i]];
                ret.push_back(n + 1);
                ret.push_back(i + 1);
                break;
            }
            else {
                m.insert(pair<int,int>(numbers[i],i));
            }
        }
        return ret;
    }
};
