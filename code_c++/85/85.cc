class Solution {
public:
    int findMaxContinuesOnes(vector<int> &v) {
        int max = v[0];
        int b = v[0];
        for (int i = 1; i < v.size(); i ++) {
            if (v[i] == 1)
                b = b + 1;
            else 
                b = 0;
            if (b > max)
                max = b;
        }
        return max;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            vector<int> v(matrix[0].size(), 1);
            for (int j = i; j < matrix.size(); j ++) {
                for (int k = 0; k < matrix[0].size(); k ++)
                    v[k] &= (matrix[j][k] - '0');
                int tempMax = (j - i + 1) * findMaxContinuesOnes(v);
                if (tempMax > max)
                    max = tempMax;
            }
        }
        return max;
    }
};