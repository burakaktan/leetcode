class Solution {
public:
    /*
    Main idea: Iterate through the input, find all 1's, perform DFS starting from each 1 which is not previously discovered by any DFS 
    (DFS function will return area of corresponding island)
    
    Time Complexity: O(n*m)
    Space Complexity: O(n*m)
    */
    int dfs(int i,int j, vector< vector<bool> > &visited, vector< vector<int> > &grid)
    {
        if(i == (int)visited.size() || i == -1 || j == -1 || j == visited[0].size() || grid[i][j] == 0 || visited[i][j])
            return 0;
   //     cout<<"discover: "<<i<<" "<<j<<endl;
        visited[i][j] = true;
        int ans = 1;
        for(int ii = -1;ii<=1;ii++)
            for(int jj = -1;jj<=1;jj++)
            {
                if((int)abs(ii) + (int)abs(jj)  != 1)
                    continue;
                ans += dfs(i+ii,j+jj,visited,grid);
            }
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector< vector<bool> >visited(n, vector<bool>(m,false));
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
              //  cout<<"i: "<<i<<" j: "<<j<<" grid: "<<grid[i][j]<<endl; 
                if(grid[i][j] == 0 || visited[i][j])
                    continue;
                int area = dfs(i,j,visited,grid);
            //    cout<<"area: "<<area<<endl;
                ans = max(ans,area);
            }
        }
        return ans;
    }
};
