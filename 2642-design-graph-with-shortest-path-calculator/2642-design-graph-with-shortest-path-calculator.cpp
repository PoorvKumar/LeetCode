class Graph 
{
private:
    int n;
    unordered_map<int,vector<vector<int>>> adjList;
    
    int dijkstraAlgorithm(int node1,int node2)
    {
        vector<int> distance(n,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min heap
        pq.push({0,node1});
        
        distance[node1]=0;
        
        for(auto x:distance)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            // int weight=pq.top().first;
            pq.pop();
            
            for(auto &x:adjList[node])
            {
                if(distance[x[0]]>distance[node]+x[1])
                {
                    distance[x[0]]=distance[node]+x[1];
                    pq.push({distance[x[0]],x[0]});
                }
            }
        }
        
        return distance[node2]!=INT_MAX?distance[node2]:-1;
    }
    
public:
    Graph(int n, vector<vector<int>>& edges) 
    {
        this->n=n;
        for(auto &x:edges)
        {
            adjList[x[0]].push_back({x[1],x[2]});
        }
    }
    
    void addEdge(vector<int> edge) 
    {
        adjList[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) 
    {
        return dijkstraAlgorithm(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */