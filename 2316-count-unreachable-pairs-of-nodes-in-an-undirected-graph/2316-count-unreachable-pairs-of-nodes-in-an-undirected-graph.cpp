class Solution 
{
private:
    int n;
    vector<vector<int>> adjList;
    vector<bool> visited;
    map<int,vector<int>> mp;
    
    void bfs(int src,int province)
    {
//         queue<int> q;
//         q.push(src);
//         visited[src]=true;
//         mp[province].push_back(src);
        
//         while(!q.empty())
//         {
//             int node=q.front();
//             q.pop();
            
//             for(auto x:adjList[node])
//             {
//                 if(!visited[x])
//                 {
//                     visited[x]=true;
//                     q.push(x);
//                     mp[province].push_back(x);
//                 }
//             }
//         }
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                // return bfs(i,province+1);
                queue<int> q;
                q.push(i);
                visited[i]=true;
                mp[province].push_back(i);

                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();

                    for(auto x:adjList[node])
                    {
                        if(!visited[x])
                        {
                            visited[x]=true;
                            q.push(x);
                            mp[province].push_back(x);
                        }
                    }
                }
                province=province+1;
            }
        }
        
        return ;
    }
    
public:
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        long long ans=0;
        this->n=n;
        
        adjList.assign(n,vector<int>());
        visited.assign(n,false);
        
        for(auto edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        bfs(0,0);
        
        // for(auto x:mp)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        long long k=0;
        for(auto x:mp)
        {
            k=k+x.second.size();
        }
        
        for(auto x:mp)
        {
            k=k-x.second.size();
            ans=ans+x.second.size()*k;
        }
        
        return ans;
    }
};