class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[i][j]
    
    int maxUncrossedUtil(vector<int>& nums1,vector<int>& nums2,int i,int j)
    {
        if(i>=nums1.size() || j>=nums2.size())
        {
            return 0;
        }
        
        if(umap.count(i) && umap[i].count(j))
        {
            return umap[i][j];
        }
        
        int notConnect1=maxUncrossedUtil(nums1,nums2,i+1,j);
        int notConnect2=maxUncrossedUtil(nums1,nums2,i,j+1);
        
        int k=j;
        while(k<nums2.size() && nums1[i]!=nums2[k]) //O(n)
        {
            k++;
        }
        
        int connect1=maxUncrossedUtil(nums1,nums2,i+1,k+1);
        if(k<nums2.size() && nums1[i]==nums2[k]) //connection made
        {
            connect1=connect1+1;
        }
        
        k=i;
        while(k<nums1.size() && nums2[j]!=nums1[k]) //O(m)
        {
            k++;
        }
        
        int connect2=maxUncrossedUtil(nums1,nums2,k+1,j+1);
        if(k<nums1.size() && nums2[j]==nums1[i]) //connection made
        {
            connect2=connect2+1;
        }
        
        int ans=max(notConnect1,notConnect2);
        ans=max(ans,connect1);
        ans=max(ans,connect2);
        
        // return ans; //Recursive Solution
        //TC: O((m+n)*4^(m+n)) //as 4 calls for every i , j
        //SC: O(m+n)+O(m+n)auxiliary stack space
        
        return umap[i][j]=ans; //Top-Down DP approach -> Recursion + Memoization
        //TC: O(m*n) //as for every i for every j Recursion calls Memoized
        //SC: O(m*n)+O(m+n)auxiliary stack space
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        // return maxUncrossedUtil(nums1,nums2,0,0);
        
        int m=nums1.size();
        int n=nums2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //dp[i][j]
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int notConnect1=dp[i+1][j];
                int notConnect2=dp[i][j+1];
                
                int k=j;
                while(k<nums2.size() && nums1[i]!=nums2[k])
                {
                    k++;
                }
                
                int connect1=k<nums2.size()?dp[i+1][k+1]:dp[i+1][k];
                if(k<nums2.size() && nums1[i]==nums2[k])
                {
                    connect1=connect1+1;
                }
                
                k=i;
                while(k<nums1.size() && nums2[j]!=nums1[k])
                {
                    k++;
                }
                
                int connect2=k<nums1.size()?dp[k+1][j+1]:dp[k][j+1];
                if(k<nums1.size() && nums2[j]==nums1[k])
                {
                    connect2=connect2+1;
                }
                
                int ans=max(notConnect1,notConnect2);
                ans=max(ans,connect1);
                ans=max(ans,connect2);
                
                dp[i][j]=ans;
            }
        }
        
        return dp[0][0];
    }
};