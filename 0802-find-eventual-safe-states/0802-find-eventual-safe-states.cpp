class Solution 
{
private:
    int n;
    vector<bool> visited;
    vector<bool> isSafe;
    
    bool checkSafe(vector<vector<int>>& graph,int src)
    {
        visited[src]=true;
        
        for(auto x:graph[src])
        {
            if(visited[x] && !isSafe[x])
            {
                return false;
            }
            
            if(!isSafe[x])
            {
                if(!checkSafe(graph,x))
                {
                    return false;
                }
            }
        }
        
        return isSafe[src]=true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        n=graph.size();
        visited.assign(n,false);
        isSafe.assign(n,false);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                if(!isSafe[i])
                {
                    if(checkSafe(graph,i))
                    {
                        isSafe[i]=true;
                    }
                }
            }
        }
        
        vector<int> res;
        for(int i=0; i<n; i++)
        {
            if(isSafe[i])
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};