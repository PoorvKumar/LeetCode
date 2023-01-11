class Solution 
{
private:
    unordered_map<int,vector<int>> adjList;
    // vector<vector<int>> adjList;
    
    int minTimeUtil(vector<bool>& hasApple,int src,int parent)
    {
        if(hasApple[src])
        {
            hasApple[src]=false;
            int x=minTimeUtil(hasApple,src,parent);
            if(x!=INT_MAX)
            {
                return x;
            }
            return 0;
        }
        
        int minTime=0;
        int countGreater=0;
        
        for(int i=0; i<adjList[src].size(); i++)
        {
            if(adjList[src][i]!=parent)
            {
                countGreater++;
                int x=minTimeUtil(hasApple,adjList[src][i],src);
                if(x!=INT_MAX)
                {
                    minTime=minTime+2+x;
                }
            }
        }
        
        if(countGreater==0 || minTime==0)
        {
            return INT_MAX;
        }
        
        return minTime;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        int countApple=0;
        for(int i=0; i<n; i++)
        {
            if(hasApple[i])
            {
                countApple++;
            }
        }
        
        if(countApple==0)
        {
            return 0;
        }
        
        for(auto x:edges) 
        {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        
        // for(auto x:adjList)
        // {
        //     cout<<x.first<<" -> ";
        //     for(auto y:x.second)
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return minTimeUtil(hasApple,0,-1);
    }
};