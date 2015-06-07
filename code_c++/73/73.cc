class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        set<int> row;
        set<int> column;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ;

        for (int i = 0; i < matrix.size(); i ++)
            for (int j = 0; j < matrix[0].size(); j ++)
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    column.insert(j);
                }

        for (set<int>::iterator it = row.begin(); it != row.end(); it ++)
              for (int i = 0; i < matrix[0].size(); i ++)
                    matrix[*it][i] = 0;

        for (set<int>::iterator it = column.begin(); it != column.end(); it ++)
              for (int i = 0; i < matrix.size(); i ++)
                    matrix[i][*it] = 0;

//        return matrix;
    }
};
