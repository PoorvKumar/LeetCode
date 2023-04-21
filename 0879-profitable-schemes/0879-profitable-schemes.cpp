class Solution 
{
private:
    long long M=1e9+7;
    unordered_map<int,unordered_map<int,unordered_map<int,int>>> umap; //umap[index][P][n]
    
    int profitableSchemesUtil(int n,int minProfit,vector<pair<int,int>>& group,int index,int P)
    {        
        if(index==group.size()) //base case
        {
            return P>=minProfit;
        }
        
        if(n<group[index].first) //base case
        {
            int exclude=profitableSchemesUtil(n,minProfit,group,index+1,P);
            return exclude;
        }
        
        if(umap.count(index) && umap[index].count(P) && umap[index][P].count(n))
        {
            return umap[index][P][n];
        }
        
        int exclude=profitableSchemesUtil(n,minProfit,group,index+1,P);
        int include=0;
        
        if(n>=group[index].first)
        {
            include=profitableSchemesUtil(n-group[index].first,minProfit,group,index+1,P+group[index].second);
        }
        
        // return (exclude+include)%M;
        
        return umap[index][P][n]=(exclude+include)%M;
    }
    
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
//         vector<pair<int,int>> vec;
        
//         for(int i=0; i<group.size(); i++)
//         {
//             vec.push_back({group[i],profit[i]});
//         }
        
//         sort(vec.begin(),vec.end());
        
//         // for(auto x:vec)
//         // {
//         //     cout<<x.first<<" "<<x.second<<endl;
//         // }
        
//         return profitableSchemesUtil(n,minProfit,vec,0,0);
        
        
//         long long P=accumulate(profit.begin(),profit.end(),0);
        int N=group.size();
        
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(101,vector<int>(n+1,0)));
        //dp[index][P][n]
        
        // for(int i=0; i<=P; i++)
        // {
        //     for(int j=0; j<=n; j++)
        //     {
        //         dp[N][i][j]=i>=minProfit;
        //     }
        // }
        for(int j=0; j<=n; j++)
        {
            dp[N][minProfit][j]=1;
        }
        
        for(int i=N-1; i>=0; i--)
        {
            for(int j=0; j<=minProfit; j++)
            {
                for(int k=0; k<=n; k++)
                {
                    int exclude=dp[i+1][j][k];
                    int include=0;
                    
                    if(k+group[i]<=n)
                    {
                        include=dp[i+1][min(minProfit,j+profit[i])][k+group[i]];
                    }
                    
                    dp[i][j][k]=(exclude+include)%M;
                }
            }
        }
        
        return dp[0][0][0];
    }
};