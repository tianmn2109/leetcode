class Solution {
public:
    int majorityElement(vector<int> &num) {
        if (num.size() == 0)
            return 0;
        if (num.size() == 1)
            return num[0];
        int maj = num[0];
        int count = 0;
        for (int i =0; i < num.size(); i ++) {
            if (count == 0 && num[i] != maj) {
                maj = num[i];
                continue;
            }
            if (num[i] == maj)
                count ++;
            else
                count --;
        }
        return maj;
    }
};
