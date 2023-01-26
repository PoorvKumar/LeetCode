class Solution 
{
private:
    unordered_map<int,vector<pair<int,int>>> adjList;
//     vector<bool> visited;
    
//     unordered_map<int,int> umap;
    
//     int findFlightsHelper(int src,int dst,int k,int mincost)
//     {
//         if(src==dst)
//         {
//             return mincost;
//         }
        
//         if(k<=0)
//         {
//             return INT_MAX;
//         }
        
//         if(umap.count(src)==1)
//         {
//             return umap[src];
//         }
        
//         int cost=INT_MAX;
//         // visited[src]=true;
        
//         for(int i=0; i<adjList[src].size(); i++) //dfs //getting TLE in case of cycles
//         {
//             pair<int,int> p=adjList[src][i];
//             if(umap.count(p.first)==0)
//             {
//                 umap[p.first]=findFlightsHelper(p.first,dst,k-1,mincost+p.second);
//             }
//             // cost=min(cost,findFlightsHelper(p.first,dst,k-1,mincost+p.second));
//             cost=min(cost,umap[p.first]);
//         }
        
//         // return cost;
//         return umap[src]=cost;
//     }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        for(auto x:flights)
        {
            adjList[x[0]].push_back({x[1],x[2]});
        }
        
        // visited.assign(n,false);
        
        // for(auto x:adjList)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y.first<<" "<<y.second<<" , "; 
        //     }
        //     cout<<endl;
        // }
        
        // int res=findFlightsHelper(src,dst,k+1,0);
        // return res!=INT_MAX?res:-1;
        
        vector<int> res(n,INT_MAX);
        res[src]=0;
        queue<vector<int>> q;
        
        
        // int stops=0;
        // q.push({stops,src,0});
        q.push({0,src,0});
        
        while(!q.empty())
        {
            vector<int> vec=q.front();
            q.pop();
            
            int stops=vec[0];
            int node=vec[1];
            int cost=vec[2];
            
            if(stops>k)
            {
                continue;
            }
            
            for(auto x:adjList[node])
            {
                int adjNode=x.first;
                int edgeWt=x.second;
                
                if(cost+edgeWt<res[adjNode] && stops<=k)
                {
                    res[adjNode]=cost+edgeWt;
                    q.push({stops+1,adjNode,res[adjNode]});
                }
                // if(cost+x.second<res[x.first] && stops<=k)
                // {
                //     res[x.first]=cost+x.second;
                //     q.push({stops+1,x.first,cost+x.second});
                // }
            }
        }
        
        return res[dst]!=INT_MAX?res[dst]:-1;
    }
};