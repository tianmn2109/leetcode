/*
 *1: 将数组排序
 *2: 依次便利数组，假设的那个前值为a，剩下的工作就是在剩下的数组中查找两个数的和b，c使得 b + c = -a 变为查找两个数的和的问题
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.size() < 3)
            return ret;

        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; i ++) {
            if (i > 0 && num[i] == num[i-1])             //＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊消除重复，加快速度，否则超时
                continue;

            int left = i + 1;
            int right = num.size() - 1;

            while (left < right) {
                if (left > i+1 && num[left] == num[left-1]) {  //＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊消除重复，加快速度，否则超时
                    left ++;
                    continue;
                }
                if (right < num.size()-1 && num[right] == num[right+1]) {  //＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊消除重复，加快速度，否则超时
                    right --;
                    continue;
                }

                int sum = num[left] + num[right];
                if ( sum == -num[i]) {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[left]);
                    v.push_back(num[right]);
                    ret.push_back(v);
                }

                if (sum > -num[i])
                    right --;
                else
                    left ++;
            }
        }
        return ret;
    }
};
