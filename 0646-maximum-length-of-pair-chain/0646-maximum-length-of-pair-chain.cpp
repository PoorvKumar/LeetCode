class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][last]
    vector<vector<int>> dp;
    
    int findLongestChainUtil(vector<vector<int>>& pairs,int index,int last)
    {
        if(index>=pairs.size())
        {
            return 0;
        }
        
        // if(umap.count(index) && umap[index].count(last))
        // {
        //     return umap[index][last];
        // }
        
        if(dp[index][last+1]!=-1)
        {
            return dp[index][last+1];
        }
        
        int exclude=findLongestChainUtil(pairs,index+1,last);
        int include=0;
        
        if(last==-1 || pairs[last][1]<pairs[index][0])
        {
            include=1+findLongestChainUtil(pairs,index+1,index);
        }
        
        // return max(exclude,include);
        
        // return umap[index][last]=max(exclude,include);
        return dp[index][last+1]=max(exclude,include);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),end(pairs));
        
        int n=pairs.size();
        
        dp.assign(n+1,vector<int>(n+1,-1));
        
        return findLongestChainUtil(pairs,0,-1);
    }
};