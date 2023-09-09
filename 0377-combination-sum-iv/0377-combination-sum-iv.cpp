class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap; //umap[index][target]
    
    int combinationSumUtil(vector<int>& nums,int index,int target)
    {
        if(index>=nums.size())
        {
            return target==0;
        }
        
        if(umap.count(index) && umap[index].count(target))
        {
            return umap[index][target];
        }

        int exclude=combinationSumUtil(nums,index+1,target);
        int include=0;
        
        if(target>=nums[index])
        {
            include=combinationSumUtil(nums,0,target-nums[index]);
        }

        // return exclude+include;
        
        return umap[index][target]=exclude+include;
    }
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        sort(nums.begin(),end(nums));
        
        return combinationSumUtil(nums,0,target);
    }
};