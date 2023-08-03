class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m=image.size();
        int n=image[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=true;
        
        int val=image[sr][sc];
        image[sr][sc]=color;
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            
            //up
            if(i>0 && !visited[i-1][j] && image[i-1][j]==val)
            {
                image[i-1][j]=color;
                visited[i-1][j]=true;
                q.push({i-1,j});
            }
            
            //down
            if(i<m-1 && !visited[i+1][j] && image[i+1][j]==val)
            {
                image[i+1][j]=color;
                visited[i+1][j]=true;
                q.push({i+1,j});
            }
            
            //left
            if(j>0 && !visited[i][j-1] && image[i][j-1]==val)
            {
                image[i][j-1]=color;
                visited[i][j-1]=true;
                q.push({i,j-1});
            }
            
            //right
            if(j<n-1 & !visited[i][j+1] && image[i][j+1]==val)
            {
                image[i][j+1]=color;
                visited[i][j+1]=true;
                q.push({i,j+1});
            }
        }
        
        return image;
    }
};