class Solution 
{
private:
    void combinationSum2Util(vector<int>& c,vector<vector<int>>& res,vector<int>& vec,int target,int index)
    {
        if(target==0)
        {
            res.push_back(vec);
            return ;
        }
        
        if(target<0 || index>=c.size())
        {
            return ;
        }
        
        int x=c[index];
        
        //include
        vec.push_back(x);
        combinationSum2Util(c,res,vec,target-x,index+1);
        vec.pop_back();
        
        //exclude
        int i=index;
        while(i<c.size() && c[i]==x)
        {
            i++;
        }
        
        combinationSum2Util(c,res,vec,target,i);
        
        return ;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> res;
        vector<int> vec;
        
        combinationSum2Util(candidates,res,vec,target,0);
        
        return res;
    }
};