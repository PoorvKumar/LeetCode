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
        
        ans=robUtil(nums,1); //when not including 1st index stat from 0
        
        nums.pop_back(); //when including 1st index but cannot include last index 
        
        umap.clear(); //umap.clear(); //for object umap of type class unordered_map<int,int> 
        //to be empty for robUtil() function call
        ans=max(ans,robUtil(nums,0));
        
        return ans;
    }
};