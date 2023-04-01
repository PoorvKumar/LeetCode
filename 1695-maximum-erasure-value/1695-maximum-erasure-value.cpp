class Solution 
{
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_map<int,int> umap;
        // unordered_map<int,pair<int,int>> umap; //umap[value]={index,prefixSum} //cannot store sum as when repeating val we need to chnage prefix sum also of other index as value removed
        int sum=0;
        int low=0;
        int ans=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(umap.count(nums[i]) && umap[nums[i]]>=low)
            {
                for(int j=low; j<umap[nums[i]]+1; j++)
                {
                    sum=sum-nums[j];
                }
                sum=sum+nums[i];
                low=umap[nums[i]]+1;
                umap[nums[i]]=i;
            }
            else
            {
                sum=sum+nums[i];
                umap[nums[i]]=i;
            }
            ans=max(ans,sum);
        }
        
        // cout<<accumulate(nums.begin(),nums.end(),0);
        
        return ans;
    }
};