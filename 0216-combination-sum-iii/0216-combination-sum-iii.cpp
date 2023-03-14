class Solution 
{
private:
    vector<vector<int>> res;
    vector<int> vec;
    
    void combinationSum3Util1(int n,int val)
    {
        if(n==0)
        {
            res.push_back(vec);
            return ;
        }
        
        if(val>9)
        {
            return ;
        }
        
        if(n>=val)
        {
            //exclude
            combinationSum3Util1(n,val+1);
            
            //include
            vec.push_back(val);
            combinationSum3Util1(n-val,val+1);
            vec.pop_back();
        }
        
        return ;
    }
    
    void combinationSum3Util2(int n,int val,int k)
    {
        if(n==0)
        {
            if(k==0)
            {
                res.push_back(vec);
            }
            return ;
        }
        
        if(val>9)
        {
            return ;
        }
        
        if(n>=val) //as val always increasing
        {
            //exclude
            combinationSum3Util2(n,val+1,k);
            
            //include
            vec.push_back(val);
            combinationSum3Util2(n-val,val+1,k-1);
            vec.pop_back();
        }
        
        return ;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
//         combinationSum3Util2(n,1,k);
        
//         return res;
        
        combinationSum3Util1(n,1);
        
        vector<vector<int>> ans;
        
        for(auto &x:res)
        {
            if(x.size()==k)
            {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};