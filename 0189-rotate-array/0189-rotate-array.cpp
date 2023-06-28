class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k=k%n;
        
        vector<int> vec(nums.begin()+n-k,nums.end());
        
        nums.erase(nums.begin()+n-k,nums.end());
        
        nums.insert(nums.begin(),vec.begin(),vec.end());
        
        // for(int i=vec.size()-1; i>=0; i--)
        // {
        //     nums.insert(nums.begin(),vec[i]);
        // }
        
        return ;
    }
};