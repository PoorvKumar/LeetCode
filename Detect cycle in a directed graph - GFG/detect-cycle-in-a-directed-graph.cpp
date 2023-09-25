//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
private:
    vector<bool> visited;
    vector<bool> path;

    bool dfs(int src,vector<int> adj[])
    {
        path[src]=true;
        visited[src]=true;
        
        for(auto x:adj[src])
        {
            if(path[x])
            {
                return true;
            }
            
            if(!visited[x])
            {
                if(dfs(x,adj))
                {
                    return true;
                }
            }
        }
        
        path[src]=false;
        
        return false;
    }
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // unordered_set<int> path;
        
        visited.assign(V,false);
        path.assign(V,false);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])  //component wise DFS
            {
                if(dfs(i,adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends