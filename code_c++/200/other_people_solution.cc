When we met a '1', the answer add 1, we also need to search all '1' which connected to it directly or indirectly, and change it to '0'. And we can use DFS or BFS to search.

1. DFS

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int res = 0;
        for(int i = 0; i < grid.size(); ++ i)
            for(int j = 0; j < grid[0].size(); ++ j)
                if(grid[i][j] == '1')
                {
                    ++ res;
                    DFS(grid, i, j);
                }
        return res;
    }
private:
    void DFS(vector<vector<char>> &grid, int x, int y)
    {
        grid[x][y] = '0';
        if(x > 0 && grid[x - 1][y] == '1')
            DFS(grid, x - 1, y);
        if(x < grid.size() - 1 && grid[x + 1][y] == '1')
            DFS(grid, x + 1, y);
        if(y > 0 && grid[x][y - 1] == '1')
            DFS(grid, x, y - 1);
        if(y < grid[0].size() - 1 && grid[x][y + 1] == '1')
            DFS(grid, x, y + 1);
    }
};
2. BFS

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int res = 0;
        for(int i = 0; i < grid.size(); ++ i)
            for(int j = 0; j < grid[0].size(); ++ j)
                if(grid[i][j] == '1')
                {
                    ++ res;
                    BFS(grid, i, j);
                }
        return res;
    }
private:
    void BFS(vector<vector<char>> &grid, int x, int y)
    {
        queue<vector<int>> q;
        q.push({x, y});
        grid[x][y] = '0';

        while(!q.empty())
        {
            x = q.front()[0], y = q.front()[1];
            q.pop();

            if(x > 0 && grid[x - 1][y] == '1')
            {
                q.push({x - 1, y});
                grid[x - 1][y] = '0';
            }
            if(x < grid.size() - 1 && grid[x + 1][y] == '1')
            {
                q.push({x + 1, y});
                grid[x + 1][y] = '0';
            }
            if(y > 0 && grid[x][y - 1] == '1')
            {
                q.push({x, y - 1});
                grid[x][y - 1] = '0';
            }
            if(y < grid[0].size() - 1 && grid[x][y + 1] == '1')
            {
                q.push({x, y + 1});
                grid[x][y + 1] = '0';
            }
        }
    }
};
