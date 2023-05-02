class Solution
{
private:
    vector<vector<int>> res;
    
    void permuteUtil(vector<int>& nums,int index)
    {
        if(index==nums.size()-1)
        {
            res.push_back(nums);
            return ;
        }
        
        for(int i=index; i<nums.size(); i++)
        {
            swap(nums[index],nums[i]);
            permuteUtil(nums,index+1);
            swap(nums[index],nums[i]);
        }
        
        return ; 
        //TC: O(n*n!)
        ///SC: O(n) auxilairy stack space (depth of recursion -> O(n))
        
    }
    
//     void permuteUtil(unordered_set<int>& uset,vector<int>& vec)
//     {
//         if(uset.empty())
//         {
//             res.push_back(vec);
//             return ;
//         }
        
//         unordered_set<int> uset1=uset;
        
//         for(auto x:uset1)
//         {
//             vec.push_back(x);
//             uset.erase(x);
//             permuteUtil(uset,vec);
//             uset.insert(x);
//             vec.pop_back();
//         }
        
//         return ;
//         //TC: O(n*n!)
//         //SC: O(n)+O(n) //depth of recursion //unordered_set<int> uset;
//     }
    
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        permuteUtil(nums,0);
        
        return res;
        
//         unordered_set<int> uset;
//         vector<int> vec;
        
//         for(auto x:nums)
//         {
//             uset.insert(x);
//         }
        
//         permuteUtil(uset,vec);
        
//         return res;
        
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