class Solution 
{
private:
    unordered_map<int,int> umap;
    int n;
    
    int minCostClimbingUtil(vector<int>& cost,int i)
    {
        if(umap.count(i)==1)
        {
            return umap[i];
        }
        
        if(i>=n)
        {
            return 0;
        }
        
        umap[i]=cost[i]+min(minCostClimbingUtil(cost,i+1),minCostClimbingUtil(cost,i+2));
        return umap[i];
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        n=cost.size();
        
        return min(minCostClimbingUtil(cost,0),minCostClimbingUtil(cost,1));
    }
};