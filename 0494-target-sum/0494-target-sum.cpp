class Solution 
{
private:
    int sum=0;
    unordered_map<int,unordered_map<int,int>> umap;
    
    int targetSumUtil(vector<int>& nums,int index,int plus,int target)
    {
        if(index==nums.size())
        {
            return 2*plus-sum==target; //plus+minus==sum && plus-minus==target must be true plus is a subset of nums
        }
        
        if(umap.count(index) && umap[index].count(plus))
        {
            return umap[index][plus];
        }
        
        int exclude=targetSumUtil(nums,index+1,plus,target);
        int include=targetSumUtil(nums,index+1,plus+nums[index],target);
        
        // return exclude+include; //Recursive Solution
        //TC: O(2^n) //as 2 (include,exclude) calls at each index
        //SC: O(n) + O(n)auxiliary space
        
        return umap[index][plus]=exclude+include;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        sum=accumulate(nums.begin(),nums.end(),0);
        
        return targetSumUtil(nums,0,0,target);
    }
};