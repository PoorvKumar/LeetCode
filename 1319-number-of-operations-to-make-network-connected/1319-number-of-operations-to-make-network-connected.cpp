class Solution 
{
private:
    vector<vector<int>> adjList;
    int n;
    vector<bool> visited;
    
    int bfs(int src);
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        this->n=n;
        adjList.assign(n,vector<int>());
        visited.assign(n,false);
        
        for(auto edge:connections)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        int totalEdges=connections.size();
        
        int disconnectedComponents=bfs(0);
        
        if(totalEdges-(n-1)>=0 && disconnectedComponents>1)
        {
            return disconnectedComponents-1;
        }
        
        if(disconnectedComponents==1)
        {
            return 0;
        }
        return -1;
    }
};

int Solution::bfs(int src)
{
    queue<int> q;
    visited[src]=true;
    q.push(src);
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            return 1+bfs(i);
        }
    }
    
    return 1;
}