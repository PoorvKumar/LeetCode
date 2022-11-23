class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<char> uset;
        
        for(int i=0; i<9; i++)  //rows
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.' && !uset.count(board[i][j]))
                {
                    uset.insert(board[i][j]);
                }
                else if(board[i][j]!='.')
                {
                    // cout<<i<<" "<<j<<" rows"<<endl;
                    return false;
                }
            }
            uset.clear();
        }
        
        for(int i=0; i<9; i++)  //columns
        {
            for(int j=0; j<9; j++)
            {
                if(board[j][i]!='.' && !uset.count(board[j][i]))
                {
                    uset.insert(board[j][i]);
                }
                else if(board[j][i]!='.')
                {
                    // cout<<i<<" "<<j<<" columns"<<endl;
                    return false;
                }
            }
            uset.clear();
        }
        
        // uset.clear();
        // int x=0; 
        
        for(int i=0; i<9; i=i+3) //grid
        {
            for(int j=0; j<9; j++)
            {
                if(j%3==0)
                {
                    uset.clear();
                    // x++;
                }
                for(int k=i; k<i+3; k++) //inintially x in place of i
                {
                    if(board[j][k]!='.' && !uset.count(board[j][k]))
                    {
                        uset.insert(board[j][k]);
                    }
                    else if(board[j][k]!='.')
                    {
                        // cout<<i<<" "<<j<<" grid\n";
                        return false;
                    }
                }
            }
        }

        return true;
    }
};