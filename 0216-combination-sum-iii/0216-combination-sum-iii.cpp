class Solution 
{
private:
    vector<vector<int>> res;
    vector<int> vec;
    
//     void combinationSum3Util(int n,int val)
//     {
//         if(n==0)
//         {
//             res.push_back(vec);
//             return ;
//         }
        
//         if(val>9)
//         {
//             return ;
//         }
        
//         if(n>=val)
//         {
//             //exclude
//             combinationSum3Util(n,val+1);
            
//             //include
//             vec.push_back(val);
//             combinationSum3Util(n-val,val+1);
//             vec.pop_back();
//         }
        
//         return ;
//     }
    
    void combinationSum3Util(int n,int val,int k)
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
            combinationSum3Util(n,val+1,k);
            
            //include
            vec.push_back(val);
            combinationSum3Util(n-val,val+1,k-1);
            vec.pop_back();
        }
        
        return ;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        combinationSum3Util(n,1,k);
        
        return res;
    }
};