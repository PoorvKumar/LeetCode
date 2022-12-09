class Solution 
{
private:
    unordered_map<int,int> umap;
public:
    int rob(vector<int>& nums,int i=0) 
    {
        if(i>=nums.size())  
        {
            return 0;
        }
        
        if(umap.count(i))  //Top-Down DP approach -> Recursion + Memoization
        {
            return umap[i];
        }
        
        umap[i+2]=rob(nums,i+2);
        umap[i+1]=rob(nums,i+1);
        
        umap[i]=max(nums[i]+umap[i+2],umap[i+1]);
        
        return umap[i];
        
        // return max(nums[i]+rob(nums,i+2),0+rob(nums,i+1));
        
        //Recursive Solution //Time Complexity -> O(2^n) where n is size of array
    }
};