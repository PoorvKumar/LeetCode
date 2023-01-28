class Solution 
{
private:
    void subsetsUtil(vector<int>& nums,vector<vector<int>>& res,vector<int>& vec,int index)
    {
        if(index>=nums.size())
        {
            res.push_back(vec);
            return;
        }
        
        vec.push_back(nums[index]);
        subsetsUtil(nums,res,vec,index+1); //include
        vec.pop_back();
        subsetsUtil(nums,res,vec,index+1); //exclude
        
        //have seen in multiple problems (important) calls of include before calls of exclude as to have remove last inserted element from object vec of type class vector<int> for backtracking 
        
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> vec;
        
        subsetsUtil(nums,res,vec,0);
        
        return res;
    }
};