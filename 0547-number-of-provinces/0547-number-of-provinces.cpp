class Solution 
{
private:
    int bfs(vector<vector<int>>& isConnected,int src)
    {
        int count=1; //atleast one province
        
        int n=isConnected.size();
        vector<bool> visited(n,false);
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            visited[x]=true;
            
            for(int i=0; i<n; i++)
            {
                if(isConnected[x][i]==1 && !visited[i])
                {
                    q.push(i);
                    // visited[i]=true;
                }
            }
            
            if(q.empty())
            {
                for(int i=0; i<n; i++)
                {
                    if(!visited[i])
                    {
                        count++;
                        q.push(i);
                        // visited[i]=true;
                        break;
                    }
                }
            }
        }
        
        return count;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        return bfs(isConnected,0);
    }
};