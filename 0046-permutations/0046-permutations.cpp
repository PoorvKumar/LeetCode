class Solution 
{
private:
    int factorial(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        
        return n*factorial(n-1);
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int fact=factorial(nums.size());
        
        vector<vector<int>> res;
        
        while(fact--)
        {
            res.push_back(nums);
            next_permutation(nums.begin(),nums.end());
        }
        
        return res;
    }
};