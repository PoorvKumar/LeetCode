class Solution 
{
private:
    unordered_map<int,unordered_set<int>> row;
    unordered_map<int,unordered_set<int>> col;
    unordered_map<int,unordered_set<int>> grid;
    
    vector<vector<int>> vec;
    
    int getGrid(int i,int j)
    {
        return vec[i][j];
    }
    
    bool solveSudokuUtil(vector<vector<char>>& board,int i,int j)
    {
        if(i==9)
        {
            return true;
        }
        
        if(board[i][j]!='.')
        {
            if(j==8)
            {
                return solveSudokuUtil(board,i+1,0);
            }
            return solveSudokuUtil(board,i,j+1);
        }
        
        // int g=i<3?j%3:(i<6?j%3+3:j%3+6);
        // int g=getGrid(i,j);
        // int g=vec[i][j];
        
        for(int k=1; k<=9; k++)
        {
            if(!row[i].count(k) && !col[j].count(k) && !grid[vec[i][j]].count(k))
            {
                board[i][j]='0'+k;
                // board[i][j]=itoa(k);
                
                row[i].insert(k);
                col[j].insert(k);
                grid[vec[i][j]].insert(k);
                
                bool ans=false;
                if(j==8)
                {
                    ans=solveSudokuUtil(board,i+1,0);
                }
                else
                {
                    ans=solveSudokuUtil(board,i,j+1);
                }
                
                if(ans)
                {
                    return true;
                }
                
                board[i][j]='.';
                
                row[i].erase(k);
                col[j].erase(k);
                grid[vec[i][j]].erase(k);
            }
        }
        
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        vec={
            {0,0,0,1,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2},
            {3,3,3,4,4,4,5,5,5},
            {3,3,3,4,4,4,5,5,5},
            {3,3,3,4,4,4,5,5,5},
            {6,6,6,7,7,7,8,8,8},
            {6,6,6,7,7,7,8,8,8},
            {6,6,6,7,7,7,8,8,8}
            };
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.')
                {
                    int val=board[i][j]-'0';
                    row[i].insert(val);
                    col[j].insert(val);
                    
                    // int g=getGrid(i,j);
                    grid[vec[i][j]].insert(val);
                }
            }
        }
        
        solveSudokuUtil(board,0,0);
        return ;
    }
};