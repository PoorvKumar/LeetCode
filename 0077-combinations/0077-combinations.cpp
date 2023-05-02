class Solution 
{
private:
    vector<vector<int>> res;
    
    void combineUtil(vector<int>& vec,int val,int n,int k)
    {
        if(vec.size()==k)
        {
            res.push_back(vec);
            return ;
        }
        
        if(val>n)
        {
            return ;
        }
        
        //exclude
        combineUtil(vec,val+1,n,k);
        
        //include
        vec.push_back(val);
        combineUtil(vec,val+1,n,k);
        vec.pop_back();
        
        return ;
    }
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> vec;
        
        combineUtil(vec,1,n,k);
        
        return res;
    }
};