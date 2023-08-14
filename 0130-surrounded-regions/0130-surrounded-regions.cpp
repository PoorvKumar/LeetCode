class Solution 
{
private:
    int m;
    int n;
    
    vector<vector<bool>> marked;
    
    void dfs(int i,int j)
    {
        marked[i][j]=true;
        
        //up
        if(i>0 && !marked[i-1][j])
        {
            dfs(i-1,j);
        }
        
        //down
        if(i<m-1 && !marked[i+1][j])
        {
            dfs(i+1,j);
        }
        
        //left
        if(j>0 && !marked[i][j-1])
        {
            dfs(i,j-1);
        }
        
        //right
        if(j<n-1 && !marked[i][j+1])
        {
            dfs(i,j+1);
        }
        
        return ;
    }
public:
    void solve(vector<vector<char>>& board) 
    {
        m=board.size();
        n=board[0].size();
        
        marked.assign(m,vector<bool>(n,false));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='X')
                {
                    marked[i][j]=true;
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O')
                {
                    if(i==0 || i==m-1 || j==0 || j==n-1)
                    {
                        if(!marked[i][j])
                        {
                            dfs(i,j);
                        }
                    }
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!marked[i][j])
                {
                    // cout<<i<<" "<<j<<endl;
                    board[i][j]='X';
                }
            }
        }
        
        return ;
    }
};