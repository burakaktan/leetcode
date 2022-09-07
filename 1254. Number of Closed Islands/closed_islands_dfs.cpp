class Solution {
public:
    bool isInside(int x,int y, vector< vector<int> > &grid)
    {
        return !(x < 0 || x >= grid.size() || y < 0 || y>= grid[0].size());
    }
    vector<pair<int,int> > getNeighbors(int x,int y, vector< vector<int> > &grid)
    {
        vector<pair<int,int> > ans;
        for(int i = -1;i<=1;i++)
        {
            for(int j = -1;j<=1;j++)
            {
                if(i*j == 0 &&  i!= j)
                {
                    int nx = x+i, ny = y+j;
                    if(isInside(nx,ny,grid))
                        ans.push_back(make_pair(nx,ny));
                }
            }
        }
        return ans;
    }
    bool dfs(int i,int j, vector< vector<int> >&grid, vector< vector<bool> >&visited)
    {
        if(visited[i][j])
            return false;
        visited[i][j] = true;
        vector<pair<int,int> > n = getNeighbors(i,j,grid);
        if(n.size() < 4)
            return false;
        bool ans = true;
        for(auto it : n)
        {
            if(visited[it.first][it.second] || grid[it.first][it.second] == 1)
                continue;
            ans &= dfs(it.first,it.second,grid,visited);
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        vector< vector<bool> > visited(grid.size(), vector<bool> (grid[0].size()));
        /*
        start dfs from all cells which aren't touching to borders
        (if cell is visited in any of previous dfs' skip that cell)
        a component is incrementing answer by one if and only is no cells touch to borders
        */
        int ans = 0;
        for(int i = 1; i<grid.size()-1;i++)
        {
            for(int j = 1;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                    continue;
                if(dfs(i,j,grid,visited))
                    ans++;
            }
        }
        return ans;
    }
};
