/*
 * reference to the answre in the Internet.
 */
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2)
            return 0;
        if (num.size() == 2)
            return abs(num[1] - num[0]);

        int max = num[0];
        int min = num[0];
        for (int i = 1; i < num.size(); i ++) {
            if (num[i] > max)
                max = num[i];
            if (num[i] < min)
                min = num[i];
        }

        int distance = (max - min) / (num.size() - 1) + 1;
        vector<vector<int> > v((max - min) / distance + 1);
        for (int i = 0; i < num.size(); i ++) {
            int x = num[i];
            int index = (x - min) / distance;
            if (v[index].empty()) {
                v[index].push_back(x);
                v[index].push_back(x);
            }
            else {
                if (x > v[index][1])
                    v[index][1] = x;
                if (x < v[index][0])
                    v[index][0] = x;
            }
        }
        int pre = 0;
        max = 0;
        for (int i = 1; i < v.size(); i ++) {
            if (v[i].empty())
                continue;
            if (v[i][0] - v[pre][1] > max)
                max = v[i][0] - v[pre][1];
            pre = i;
        }
        return max;
    }
};
