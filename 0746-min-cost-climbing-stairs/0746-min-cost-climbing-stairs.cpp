class Solution 
{
private:
    unordered_map<int,int> umap;
    int n;
    
    //Top-Down DP approach-> Recursion + Memoization
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
        
        if(umap.count(i+1)==0)
        {
            umap[i+1]=minCostClimbingUtil(cost,i+1);
        }
        if(!umap.count(i+2))
        {
            umap[i+2]=minCostClimbingUtil(cost,i+2);
        }
        
        // umap[i]=cost[i]+min(minCostClimbingUtil(cost,i+1),minCOstClimbingUtil(cost,i+2)); //Recurive Solution
        umap[i]=cost[i]+min(umap[i+1],umap[i+2]);
        return umap[i];
    }
    
//     //Bottom-Up DP approach-> Tabulation
//     int minCostClimbingUtil(vector<int>& cost,int k)
//     {
//         int mincost=0;
        
//         for(int i=k; i<n-3; i++)
//         {
//             mincost=mincost+cost[i]+min(cost[i+1],cost[i+2]);
//         } 
        
//         return mincost;
//     }
    
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        n=cost.size(); //Top-Down DP approach-> Recursion+Memoization
        
        return min(minCostClimbingUtil(cost,0),minCostClimbingUtil(cost,1));
    }
};