class Solution 
{
private:
    unordered_map<int,vector<int>> umap;
    
    int dfs(vector<int>& informTime,int head)
    {
        int ans=informTime[head];
        int val=0;
        
        for(auto x:umap[head])
        {
            val=max(val,dfs(informTime,x));
        }
        
        ans=ans+val;
        
        return ans;
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        for(int i=0; i<n; i++)
        {
            umap[manager[i]].push_back(i);
        }
        
        return dfs(informTime,headID);
    }
};