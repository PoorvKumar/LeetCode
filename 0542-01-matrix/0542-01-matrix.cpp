class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> dist(m,vector<int>(n,0));
        
        queue<vector<int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j,0});
                    visited[i][j]=true;
                }
            }
        }
        
        while(!q.empty())
        {
            vector<int> vec=q.front();
            q.pop();
            
            int i=vec[0];
            int j=vec[1];
            int val=vec[2];
            
            dist[i][j]=val;
            
            //up
            if(i>0 && !visited[i-1][j])
            {
                q.push({i-1,j,val+1});
                visited[i-1][j]=true;
            }
            
            //down
            if(i<m-1 && !visited[i+1][j])
            {
                q.push({i+1,j,val+1});
                visited[i+1][j]=true;
            }
            
            //left
            if(j>0 && !visited[i][j-1])
            {
                q.push({i,j-1,val+1});
                visited[i][j-1]=true;
            }
            
            //right
            if(j<n-1 && !visited[i][j+1])
            {
                q.push({i,j+1,val+1});
                visited[i][j+1]=true;
            }
        }
        
        return dist;
    }
};