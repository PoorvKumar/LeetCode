class Solution 
{
private:
    bool compareVec(vector<int>& v1,vector<int>& v2)
    {
        if(v1.size()!=v2.size())
        {
            return false;
        }
        
        // sort(v2.begin(),v2.end());
        
        for(int i=0; i<v1.size(); i++)
        {
            if(v1[i]!=v2[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void combinationSumUtil(vector<int>& c,vector<vector<int>>& res,vector<int>& vec,int target)
    {
        if(target<0)
        {
            return ;
        }
        
        if(target==0)
        {
            res.push_back(vec);
            return;
        }
        
        for(auto x:c)
        {
            if(target>=x)
            {
                vec.push_back(x);
                // cout<<x<<" "<<target<<endl;
                combinationSumUtil(c,res,vec,target-x);
                vec.pop_back();
            }            
        }
        
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> res;
        vector<int> vec;
        
        combinationSumUtil(candidates,res,vec,target);
        
        if(res.empty())
        {
            return res;
        }
        
        for(auto &x:res)
        {
            sort(x.begin(),x.end());
        }
        
        sort(res.begin(),res.end());
        
        vector<vector<int>> ans;
        // ans.push_back(res[0]);
        
        for(auto x:res)
        {
            bool flag=true;
            for(auto y:ans)
            {
                if(compareVec(x,y))
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                ans.push_back(x);
            }
        }
         
        // return res;
        return ans;
    }
};