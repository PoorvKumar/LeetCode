class Solution 
{
private:
    void combinationSumUtil(vector<int>& c,vector<vector<int>>& res,vector<int>& vec,int target,int index)
    {
        if(target<0 || index>=c.size())
        {
            return ;
        }
        
        if(target==0)
        {
            res.push_back(vec);
            return ;
        }
        
        //not include
        combinationSumUtil(c,res,vec,target,index+1);
        
        //include
        vec.push_back(c[index]);
        combinationSumUtil(c,res,vec,target-c[index],index);
        vec.pop_back();
        
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> vec;
        
        combinationSumUtil(candidates,res,vec,target,0);
        
        return res;
    }
};