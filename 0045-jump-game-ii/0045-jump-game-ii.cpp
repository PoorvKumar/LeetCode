class Solution 
{
private:
    unordered_map<int,int> umap;
    
    int jumpHelper(vector<int>& nums,int index)
    {
        if(index>=nums.size()-1)
        {
            umap[nums.size()-1]=0;
            return 0;
        }
        
        int minim=INT_MAX;
        
        for(int i=1; i<=nums[index]; i++)
        {
            if(!umap.count(index+i))
            {
                umap[index+i]=jumpHelper(nums,index+i);
            }
            
            minim=min(minim,umap[index+i]);
        }
        
        umap[index]=minim<INT_MAX?1+minim:minim;
        
        return umap[index];
    }
public:
    int jump(vector<int>& nums) 
    {
        return jumpHelper(nums,0);
    }
};