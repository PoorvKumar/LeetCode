class Solution 
{
private:
    vector<vector<pair<int,bool>>> adjList;
    
    void dijkstraAlgo(int src,vector<int>& ans) //bfs()
    {
        //implemented dijkstra's algorithm to be according to the problem
        
        // queue<pair<int,bool>> q;
        queue<vector<int>> q;
        //as edges wts same so not necessary to use object of type class priority_queue<int,vector<int>,greater<int>> to implement min heap data structure
        
        ans[src]=0;
        q.push({0,0,-1}); //index,distance,color
        
        //color for 0 -> -1
        // p[2]!=x.second && x.first!=-1
        // for(auto x:adjList[src])
        // {
        //     ans[x.first]=1;
        //     // q.push(x);
        //     q.push(vector<int>({x.first,1,x.second})); //{index,distance,color}
        // }
        
        while(!q.empty())
        {
            vector<int> p=q.front();
            q.pop();
            
            if(ans[p[0]]==-1)
            {
                ans[p[0]]=p[1];
            }
            
            for(auto &x:adjList[p[0]])
            {
                if(p[2]!=x.second && x.first!=-1) //(!p[2]==x.second && x.first!=-1) changed 
                {
                    // if(ans[x.first]==-1)
                    // {
                    //     ans[x.first]=1+ans[p.first];
                    // }
                    
                    q.push({x.first,p[1]+1,x.second}); 
                    x.first=-1;
                }
            }
        }
        
        // for(auto &x:ans)
        // {
        //     if(x==INT_MAX)
        //     {
        //         x=-1;
        //     }
        // }
        
        return ;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        //red->1 blue->0
        
        // adjList.assign(n); //wrong
        adjList.assign(n,vector<pair<int,bool>>());
        
        for(auto x:redEdges)
        {
            adjList[x[0]].push_back(make_pair(x[1],1));
            // adjList[x[0]].push_back({x[1],1});
        }
        
        for(auto x:blueEdges)
        {
            adjList[x[0]].push_back(make_pair(x[1],0));
            // adjList[x[0]].push_back({x[1],0});
        }
        
        vector<int> ans(n,-1);
        dijkstraAlgo(0,ans);
        
        // for(auto x:adjList)
        // {
        //     for(auto y:x)
        //     {
        //         cout<<y.first<<" "<<y.second<<" , ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
    }
};


// 38 / 90 testcases passed
// 5
// [[0,1],[1,2],[2,3],[3,4]]
// [[1,2],[2,3],[3,1]]

// Output: [0,1,2,3,-1]
// Expected Output: [0,1,2,3,7]

// for this testcase there is a cycle present which gives the path 0 -> 4 with alternating colors nut the algorithm is not giving that path

//we can remove edges from adjacency list for nodes which are visited in case of cycles


