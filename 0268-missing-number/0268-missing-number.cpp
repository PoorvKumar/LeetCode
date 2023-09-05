class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size();
        int val=(n*(n+1))/2;
        int sum=accumulate(nums.begin(),end(nums),0);
        
        // cout<<val<<" "<<sum<<endl;
        
        return val-sum;
    }
};