class Solution 
{
private:
    int maximizeScore(vector<int>& nums,int left,int right,bool player)
    {
        if(left>right)
        {
            return 0;
        }
        
        if(left==right)
        {
            return nums[left];
        }
        
        int first=(!player?nums[left]:0)+maximizeScore(nums,left+1,right,!player);
        int last=(!player?nums[right]:0)+maximizeScore(nums,left,right-1,!player);
        
        int ans=(!player?max(first,last):min(first,last));
        return ans;
    }
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        long long scoreA=maximizeScore(nums,0,nums.size()-1,0);
        
        long long sum=accumulate(nums.begin(),end(nums),0);
        
        return scoreA>=sum-scoreA;
    }
};