class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        if (rowIndex == 0)
            return v;
        for (int i = 1; i <= rowIndex; i ++) {
            v.push_back(1);
            for (int j = i - 1; j >0; j --)
                v[j] = v[j] + v[j - 1];
        }
        return v;
    }
};
