class Solution
{
private:
    vector<vector<int>> res;
    
    void permuteUtil(unordered_set<int>& uset,vector<int>& vec)
    {
        if(uset.empty())
        {
            res.push_back(vec);
            return ;
        }
        
        unordered_set<int> uset1=uset;
        
        for(auto x:uset1)
        {
            vec.push_back(x);
            uset.erase(x);
            permuteUtil(uset,vec);
            uset.insert(x);
            vec.pop_back();
        }
        
        return ;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        unordered_set<int> uset;
        vector<int> vec;
        
        for(auto x:nums)
        {
            uset.insert(x);
        }
        
        permuteUtil(uset,vec);
        
        return res;
        
//         int fact=factorial(nums.size());
        
//         vector<vector<int>> res;
        
//         while(fact--)
//         {
//             res.push_back(nums);
//             next_permutation(nums.begin(),nums.end());
//         }
        
//         return res;
    }
};