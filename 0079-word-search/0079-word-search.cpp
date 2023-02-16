class Solution 
{
private:
    int m;
    int n;
    vector<vector<bool>> visited;
    
    bool existUtil(vector<vector<char>>& board,string& s,int x,int y,int index)
    {
        if(index==s.length()-1 && board[x][y]==s[index] && !visited[x][y])
        {
            return true;
        }
        
        if(index>=s.length() || board[x][y]!=s[index] || visited[x][y])
        {
            return false;
        }
        
        visited[x][y]=true;
        
        //up
        if(x>0 && existUtil(board,s,x-1,y,index+1))
        {
            return true;
        }
        
        //down
        if(x<m-1 && existUtil(board,s,x+1,y,index+1))
        {
            return true;
        }
        
        //left
        if(y>0 && existUtil(board,s,x,y-1,index+1))
        {
            return true;
        }
        
        //right
        if(y<n-1 && existUtil(board,s,x,y+1,index+1))
        {
            return true;
        }
        
        visited[x][y]=false;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        m=board.size();
        n=board[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==word[0])
                {
                    visited.assign(m,vector<bool>(n,false));
                    if(existUtil(board,word,i,j,0))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};