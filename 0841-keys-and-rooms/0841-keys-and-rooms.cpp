class Solution 
{
private:
    int n;
    vector<bool> visited;
    
    void dfs(vector<vector<int>>& rooms,int source)
    {
        visited[source]=true;
        
        for(int i=0; i<rooms[source].size(); i++)
        {
            int x=rooms[source][i];
            
            if(!visited[x])
            {
                dfs(rooms,x);
            }
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        //adjacency list given -> dfs of graph
        
        n=rooms.size();
        visited.assign(n,false);
        
        dfs(rooms,0);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        
        return true;
    }
};