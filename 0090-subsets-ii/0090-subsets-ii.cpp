class Solution 
{
private:
    void subsets2Util(vector<int>& nums,vector<vector<int>>& res,vector<int>& vec,int index)
    {
        if(index>=nums.size())
        {
            res.push_back(vec);
            return ;
        }
        
        int x=nums[index];
        
        //exclude
        int i=index;
        while(i<nums.size() && nums[i]==x)
        {
            i++;
        }
        
        subsets2Util(nums,res,vec,i);
        
        //include
        vec.push_back(x);
        subsets2Util(nums,res,vec,index+1);
        vec.pop_back();
        
        return ;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        vector<int> vec;
        
        subsets2Util(nums,res,vec,0);
        
        return res;
    }
};