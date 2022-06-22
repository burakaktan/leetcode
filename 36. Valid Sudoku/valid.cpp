/*
Time Complexity: O(n)
Space Complexity: O(sqrt(n))

where n is number of cells in the sudoku board

note: because we're given that board is always 9x9, we can assume that time and space complexities are O(1)
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for(const vector<char> &v : board)
        {
            unordered_set<char> s;
            for(char ch : v)
            {
                if(ch == '.')
                    continue;
                if(s.find(ch) != s.end())
                    return false;
                s.insert(ch);
            }
        }
        //check columns
        for(int i = 0;i<9;i++)
        {
            unordered_set<char> s; 
            for(int j = 0;j<9;j++)
            {
               char ch = board[j][i];
                if(ch == '.')
                    continue;
                if(s.find(ch) != s.end())
                    return false;
                s.insert(ch);
            }
        }
        //check sub grids
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                int ru = i*3;
                int cl = j*3;
                unordered_set<char> s; 
                for(int a = ru;a<ru+3;a++)
                {
                    for(int b = cl;b<cl+3;b++)
                    {
                        char ch = board[a][b];
                        if(ch == '.')
                            continue;
                        if(s.find(ch) != s.end())
                            return false;
                        s.insert(ch);
                    }
                }
            }
        }
        return true;
    }
};
