class Solution 
{
private:
    int n;
    // vector<vector<int>> adjList;
    unordered_map<int,vector<int>> adjList;
    vector<int> res;
    
    void dfs(int src,int parent)
    {
        res.push_back(src);
        
        for(auto x:adjList[src])
        {
            if(x!=parent)
            {
                dfs(x,src);
            }
        }
        
        return ;
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        n=adjacentPairs.size()+1;
        
        for(auto x:adjacentPairs)
        {
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }
        
        int src=-1;
        for(auto x:adjList)
        {
            if(x.second.size()==1)
            {
                src=x.first;
                break;
            }
        }
        
        dfs(src,-1);
        
        return res;
    }
};