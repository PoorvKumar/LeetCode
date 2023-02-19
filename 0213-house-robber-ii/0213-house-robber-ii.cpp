class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int robUtil(vector<int>& nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        
        // return max(robUtil(nums,index+1),nums[index]+robUtil(nums,index+2)); //Recursive Solution
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        umap[index+1]=robUtil(nums,index+1);//Top-Down DP approach -> Recursion + Memoizaion
        umap[index+2]=robUtil(nums,index+2);
        
        umap[index]=max(umap[index+1],nums[index]+umap[index+2]);
        return umap[index];
    }
public:
    int rob(vector<int>& nums)
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        int ans=0;
        
        //when not including start index start form index 1
        //when including start index nums.pop_back(); to remove last index element as cannot be  included
        
        ans=robUtil(nums,1);
        
        nums.pop_back();
        
        umap.clear();
        ans=max(ans,robUtil(nums,0));
        
        return ans;
    }
};