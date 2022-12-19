class Solution 
{
private:
    int n;
    unordered_map<int,vector<int>> adjList;
    vector<vector<int>> edgesList;
    
    vector<bool> visited;
    
    bool dfs(int source,int dest)
    {
        if(source==dest)
        {
            return true;
        }
        
        visited[source]=true;
        
        for(int i=0; i<adjList[source].size(); i++) //adjacency list of source
        {
            int x=adjList[source][i];
            if(!visited[x] && dfs(x,dest))
            {
                return true;
            }
        }
        
        return false;
    }
    
public:
    bool validPath(int N, vector<vector<int>>& edges, int source, int destination) 
    {
        n=N;
        visited.assign(n,false);
        
        for(auto x:edges)  //adjacency list
        {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        
        // for(auto x:adjList) //adjacency list
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
//         int E=edges.size();
//         int i=0;
//         while(i!=E) //edge list
//         {
//             edges.push_back({edges[i][1],edges[i][0]});
//             i++;
//         }
        
//         sort(edges.begin(),edges.end());
//         edgesList=edges;
        
        // for(auto x:edges)
        // {
        //     for(auto y:x)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dfs(source,destination);
    }
};