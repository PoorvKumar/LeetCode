class Solution 
{
private:
    // unordered_map<int,vector<pair<int,double>>> adjList;
    vector<vector<pair<int,double>>> adjList;
    
    // vector<bool> visited;
    
    double maxProbUtil(int start,int end)
    {
        priority_queue<pair<double,int>> pq;
        
        vector<double> prob(adjList.size(),0);
        prob[start]=1;
        
        pq.push({1,start});
        
        while(!pq.empty())
        {
            pair<double,int> p=pq.top();
            pq.pop();
            
            for(auto x:adjList[p.second])
            {
                double val=p.first*x.second;
                if(prob[x.first]<val)
                {
                    prob[x.first]=val;
                    pq.push({val,x.first});
                }
            }
        }
        
        return prob[end];
    }
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        adjList.assign(n,vector<pair<int,double>>());
        
        for(int i=0; i<edges.size(); i++)
        {
            adjList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        // for(auto x:adjList)
        // {
        //     for(auto y:x)
        //     {
        //         cout<<y.first<<" "<<y.second<<" , ";
        //     }
        //     cout<<endl;
        // }
        
        return maxProbUtil(start,end);
        
        // visited.assign(n,false);
        
        // return maxProbabiltyUtil(start,end); //got TLE 9/18 testcases passed
    }
};

// double maxProbabiltyUtil(int start,int end)
// {
//     if(start==end)
//     {
//         return 1;
//     }

//     visited[start]=true;

//     double ans=0;

//     for(auto x:adjList[start])
//     {
//         if(!visited[x.first])
//         {
//             double val=x.second*maxProbabiltyUtil(x.first,end);
//             ans=max(ans,val);
//         }
//     }

//     visited[start]=false;

//     return ans;
// }