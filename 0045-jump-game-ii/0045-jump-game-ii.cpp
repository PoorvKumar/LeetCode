class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int jumpHelper(vector<int>& nums,int index)
    {
        if(index>=nums.size()-1) //base case
        {
            return 0;
        }
        
        if(umap.count(index))
        {
            return umap[index];
        }
        
        int minim=INT_MAX;
        
        for(int i=1; i<=nums[index]; i++) //Recursive Solution
        {
            int x;
            if(!umap.count(index+i))
            {
                x=jumpHelper(nums,index+i);
            }
            else
            {
                x=umap[index+i];
            }
            if(x<INT_MAX)
            {
                x++;
            }
            minim=min(minim,x);
        }
        
        return umap[index]=minim;
    }
public:
    int jump(vector<int>& nums) 
    {
        int ans=jumpHelper(nums,0);
        
        return ans!=INT_MAX?ans:-1;
    }
};