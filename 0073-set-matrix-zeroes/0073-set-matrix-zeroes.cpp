class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        queue<pair<int,int>> q;
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            
            int i=p.first;
            int j=p.second;
            
            int x=i;
            int y=j;
            
            //up
            while(--x>=0)
            {
                matrix[x][y]=0;
            }
            
            x=i;
            //down
            while(++x<=m-1)
            {
                matrix[x][y]=0;
            }
            
            x=i;
            //left
            while(--y>=0)
            {
                matrix[x][y]=0;
            }
            
            y=j;
            //right
            while(++y<=n-1)
            {
                matrix[x][y]=0;
            }
        }
        
        return ;
    }
};