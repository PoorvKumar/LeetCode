class Solution 
{
private:
    unordered_map<int,int> umap;
public:
//     int robTopDown(vector<int>& nums,int i=0) 
//     {
//         if(i>=nums.size())  
//         {
//             return 0;
//         }
        
//         if(umap.count(i))  //Top-Down DP approach -> Recursion + Memoization
//         {
//             return umap[i];
//         }
        
//         umap[i+2]=rob(nums,i+2);
//         umap[i+1]=rob(nums,i+1);
        
//         umap[i]=max(nums[i]+umap[i+2],umap[i+1]);
        
//         return umap[i];
        
//         // return max(nums[i]+rob(nums,i+2),0+rob(nums,i+1));
        
//         //Recursive Solution //Time Complexity -> O(2^n) where n is size of array
//     }
    
    
    int rob(vector<int>& nums)
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        int n=nums.size();
        
        nums[n-2]=max(nums[n-2],nums[n- 1]);
        
        for(int i=n-3; i>=0; i--)
        {
            nums[i]=max(nums[i]+nums[i+2],nums[i+1]);
        }
        
        return nums[0];
    }
    
};