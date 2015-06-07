#include <utility>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        if (grid.size() == 0)
            return 0;
        if (grid[0].size() == 0)
            return 0;
        int count = 0;

        for (int i = 0; i < grid.size(); i ++)
            for (int j = 0; j < grid[0].size(); j ++)
            {
                if (grid[i][j] == '1')
                {
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while (!q.empty())
                    {
                        pair<int, int> temp = q.front();
                        q.pop();
                        int row = temp.first;
                        int col = temp.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1')
                        {
                            grid[row - 1][col] = '0';
                            q.push(make_pair(row - 1, col));
                        }
                        if (row + 1 < grid.size() && grid[row + 1][col] == '1')
                        {
                            grid[row + 1][col] = '0';
                            q.push(make_pair(row + 1, col));
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1')
                        {   
                            grid[row][col - 1] = '0';
                            q.push(make_pair(row, col - 1));
                        }
                        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1')
                        {
                            grid[row][col + 1] = '0';
                            q.push(make_pair(row, col + 1));
                        }
                    }
                    count ++;
                }
            }
        return count;
    }
};

int main()
{
	vector<vector<char > > v;
	vector<char> vv;
	vv.push_back('1');
	vv.push_back('0');
	v.push_back(vv);
	Solution s;
	cout << s. numIslands(v) << endl;
	return 0;
}
