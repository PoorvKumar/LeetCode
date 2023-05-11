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
        //TC: O(m*n) //as for every i for evry j Recursion calls Memoized
        //SC: O(m*n)+O(m+n)auxiliary stack space
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        return maxUncrossedUtil(nums1,nums2,0,0);
    }
};