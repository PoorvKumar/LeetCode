class Solution 
{
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int> res(nums.size(),-1);
        
        long long sum=0;
        int windowSize=2*k+1;
        
        if(windowSize>n)
        {
            return res;
        }
        
        for(int i=0; i<windowSize; i++)
        {
            sum=sum+nums[i];
        }
        
        if(k<n)
        {
            res[k]=sum/windowSize;
        }
        
        for(int i=k; i<n-k; i++)
        {
            res[i]=sum/windowSize;
            if(i+k+1<n)
            {
                sum=sum-nums[i-k];
                sum=sum+nums[i+k+1];
            }
            else
            {
                break;
            }
        }
        
        return res; //Sliding Window Approach
        //TC: O(n)
        //SC: O(n)
    }
};