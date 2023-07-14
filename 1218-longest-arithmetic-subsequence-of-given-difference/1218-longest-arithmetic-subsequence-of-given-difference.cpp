class Solution 
{
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        unordered_map<int,int> umap;
        
        int ans=1;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(umap.count(arr[i]-difference))
            {
                umap[arr[i]]=1+umap[arr[i]-difference];
            }
            else
            {
                umap[arr[i]]=1;
            }
            
            ans=max(ans,umap[arr[i]]);
        }
        
        return ans;
    }
};