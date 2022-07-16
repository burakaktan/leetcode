/*
Time Complexity: O(m*n*maxMove)
Space Complexity: O(m*n)
*/
class Solution {
public:
    const int mod = 1e9+7;
    int get(vector< vector<int> > &v,int i,int j)
    {
        if(i < 0 || i >= v.size() || j < 0 || j>= v[0].size())
            return 0;
        return v[i][j];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        vector< vector<int> > reach(m, vector<int>(n,0));
        reach[startRow][startColumn] = 1;
        for(int move = 1;move <= maxMove;move++)
        {
            vector< vector<int> > new_reach(m, vector<int>(n,0));
            for(int i = -1; i <= m;i++)
            {
                for(int j = -1; j<=n;j++)
                {
                    int *refer;
                    if(i == -1 || j == -1 || i == m || j == n)
                        refer = &ans;
                    else
                        refer = &new_reach[i][j];
                    *refer += get(reach,i-1,j);
                    *refer %= mod;
                    *refer += get(reach,i+1,j);
                    *refer %= mod;
                    *refer += get(reach,i,j-1);
                    *refer %= mod;
                    *refer += get(reach,i,j+1);
                    *refer %= mod;
                }
            }
            swap(reach,new_reach);
        }
        return ans;
    }
};
