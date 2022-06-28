class Solution {
public:
    /*
    Time Complexity: O(n*m)
    Space Complexity: O(1) // we're modifying the input
    */
    int get(const vector<vector<int> >&v,int x,int y)
    {
        if(x < 0 || y < 0 || x >= v.size() || y >= v[0].size())
            return INT_MAX;
        return v[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = grid.size()-1;i>-1;i--)
        {
            for(int j = grid[0].size()-1;j >-1;j--)
            {
                if(i == grid.size()-1 && j == grid[0].size()-1)
                    continue;
                grid[i][j] += min(get(grid,i+1,j),get(grid,i,j+1));
            }
        }
        return grid[0][0];
    }
};
