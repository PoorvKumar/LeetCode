class Solution 
{
private:
    vector<vector<int>> res;
    vector<int> vec;
    
    void combinationSumUtil(vector<int>& candidates,int index,int target)
    {
        if(target<=0)
        {
            if(target==0 && !vec.empty())
            {
                res.push_back(vec);
            }
            
            return ;
        }
        
        if(index>=candidates.size())
        {
            return ;
        }
        
        //exclude
        combinationSumUtil(candidates,index+1,target);
        
        //include
        vec.push_back(candidates[index]);
        combinationSumUtil(candidates,index,target-candidates[index]);
        vec.pop_back();
        
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        combinationSumUtil(candidates,0,target);
        
        return res;
    }
};