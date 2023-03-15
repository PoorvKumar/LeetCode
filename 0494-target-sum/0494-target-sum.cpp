class Solution 
{
private:
    unordered_map<int,unordered_map<int,int>> umap;
    
    int targetSumUtil(vector<int>& nums,int index,int target)
    {
        if(index==nums.size())
        {
            // return target==0?1:0;
            return target==0;
        }
        
        if(umap.count(index) && umap[index].count(target))
        {
            return umap[index][target];
        }
        
        int plus=targetSumUtil(nums,index+1,target-nums[index]);
        int minus=targetSumUtil(nums,index+1,target+nums[index]);
        
        // return plus+minus; //recursive Solution
        //TC: O(2^n) //as 2 calls(plus,minus) for every index , n index
        //SC: O(n) + O(n)auxiliary space
        
        return umap[index][target]=plus+minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return targetSumUtil(nums,0,target);
    }
};