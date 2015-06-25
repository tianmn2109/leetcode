// 1
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ints(rowIndex + 1, 1);
        for(int row = 0; row < rowIndex; row++) {
            for(int col = row; col > 0; col--) {
                ints[col] += ints[col - 1];
            }
        }
        return ints;
    }
};

// 2
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex + 1);
        vi[0] = 1;
        for (int i = 0; i <= rowIndex ; ++i)
        {
            for (int j = i; j > 0; --j)
            {
                vi[j] = vi[j] + vi[j-1];
            }
        }
        return vi;
    }
};
