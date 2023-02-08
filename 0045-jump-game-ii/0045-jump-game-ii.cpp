class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int jumpHelper(vector<int>& nums,int index) //Top-Down DP approach -> Recursion + Memoization
    {
        if(index>=nums.size()-1) //base case
        {
            return 0;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        int minim=INT_MAX;
        
        for(int i=1; i<=nums[index]; i++) //Recursive Solution
        {
            int x;
            if(!umap.count(index+i))
            {
                x=jumpHelper(nums,index+i);
            }
            else
            {
                x=umap[index+i];
            }
            if(x<INT_MAX)
            {
                x++;
            }
            minim=min(minim,x);
        }
        
        return umap[index]=minim;
    }
public:
    int jump(vector<int>& nums) 
    {
//         int ans=jumpHelper(nums,INT_MAX);
        
//         return ans!=INT_MAX?ans:-1;
        
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=1; j<=nums[i]; j++)
            {
                if(i+j<n && dp[i+j]!=INT_MAX)
                {
                    dp[i]=min(dp[i],1+dp[i+j]);
                }
            }
        }
        
        return dp[0];
    }
};