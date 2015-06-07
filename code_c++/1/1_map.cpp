/*算法思想
 *采用map  复杂度为 lgn
 */

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        map<int,int> m;
        for (int i = 0; i < numbers.size(); ++ i) {
            if (!m.count(numbers[i])) {
                m.insert(pair<int,int>(numbers[i],i));
            }
            if (m.count(target - numbers[i])) {
                int n = m[target - numbers[i]];
                if (n < i) {                            	//防止 找到的是自身刚刚插入的值
                    ret.push_back(n + 1);
                    ret.push_back(i + 1);
                    break;
                }
            }
        }
        return ret;
    }
};