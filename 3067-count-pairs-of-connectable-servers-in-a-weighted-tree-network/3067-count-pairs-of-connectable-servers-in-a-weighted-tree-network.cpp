class Solution 
{
private:
    vector<vector<pair<int,int>>> adjList;
    
    int countDivDistNodes(int node,int parent,int distance,int signalSpeed)
    {
        int ans=0;
        
        if(distance%signalSpeed==0)
        {
            ans++;
        }
        
        int m=adjList[node].size();
        for(int i=0; i<m; i++)
        {
            int nd=adjList[node][i].first;
            int dist=adjList[node][i].second;
            
            if(nd!=parent)
            {
                int count=countDivDistNodes(nd,node,distance+dist,signalSpeed);
                ans+=count;
            }
        }
        
        return ans;
    }
    
    int countPairsUtil(int node,int signalSpeed)
    {
        int m=adjList[node].size();
        if(m<2)
        {
            return 0;
        }
        
        vector<int> countArr(m,0);
        
        for(int i=0; i<m; i++)
        {
            int nd=adjList[node][i].first;
            int dist=adjList[node][i].second;
            
            int k=countDivDistNodes(nd,node,dist,signalSpeed);
            countArr[i]=k;
        }
        
        //i think the problem is here, we have count of nodes in the subtrees, whose distance is divisible by signal speed
        //now how to find pairs
        //[1,2,0,4]
        
        //so number of pairs that can be made is sum of product of two at a time...
        //1*2+1*4+2*4
        
        // sum of product of two at a time
        
        int countVal=0;
        
        for(int i=0; i<m; i++)
        {
            if(countArr[i]!=0)
            {
                countVal++;
            }
        }
        
        if(countVal<2)
        {
            return 0;
        }
        
        int ans=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=i+1; j<m; j++)
            {
                ans=ans+countArr[i]*countArr[j];
            }
        }
        
        return ans;
    }
    
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) 
    {
        int n=edges.size()+1;
        
        adjList.assign(n,vector<pair<int,int>>());
        
        for(auto &x:edges)
        {
            adjList[x[0]].push_back(make_pair(x[1],x[2]));
            adjList[x[1]].push_back({x[0],x[2]});
        }
        
        vector<int> res(n,0);
        
        for(int i=0; i<n; i++)
        {
            int countPairs=countPairsUtil(i,signalSpeed);
            res[i]=countPairs;
        }
        
        return res; // TC: O(n*m*m*m) // SC: O(n*m+n+m+m)
    }
};