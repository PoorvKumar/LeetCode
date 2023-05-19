class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        unordered_set<int> uset1;
        unordered_set<int> uset2;
        
        queue<int> q;
        // vector<bool> visited(graph.size(),false);
        
        q.push(0);
        uset1.insert(0);
        // visited[0]=true;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(int i=0; i<graph[node].size(); i++)
            {
                int x=graph[node][i];
                if(uset1.count(node) && uset1.count(x) || uset2.count(node) && uset2.count(x))
                {
                    return false;
                }
                
                if(!uset1.count(x)  && !uset2.count(x))
                {
                    q.push(x);
                }

                if(uset1.count(node))
                {
                    uset2.insert(x);
                    continue;
                }
                uset1.insert(x);
            }
            
            if(q.empty())
            {
                for(int i=0; i<graph.size(); i++)
                {
                    if(!uset1.count(i)  && !uset2.count(i) && !graph[i].empty()) 
                    {
                        q.push(i); //also the adjacency list is not empty
                        break;
                    }
                }
            }
        }
        
        return true;
    }
};