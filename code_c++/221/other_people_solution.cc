class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxA = 0;
        const int m = matrix.size();
        if(!m) return maxA;
        const int n = matrix[0].size();
        if(!n) return maxA;
        int area[2][n]; // DP table to save the maximum square (with bottom-right corner at [i][j]) edge length 
        int cur = 0, next =1; // ping-pog switch index
        fill_n(area[0],n,0);

        int i, j;

        for(i=0;i<m;i++)
        {
            area[next][0] = matrix[i][0] == '1'; // the first colume
            for(j=1; j<n; j++)
                area[next][j] = matrix[i][j]=='1'? (min(area[cur][j-1],min(area[next][j-1],area[cur][j])) + 1):0; //DP update
            for(j=0; j<n && maxA<=i; j++) if(maxA<area[next][j]) maxA = area[next][j]; // find the maximum square for the current row
            cur = next;
            next = 1-cur;
        }
        return maxA * maxA;
    }
};
