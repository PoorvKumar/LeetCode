class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        unsigned long long minim=INT_MAX;
        int minIndex=0;
        int n=nums.size();
        
        unsigned long long lsum=0;
        unsigned long long rsum=0;
        long long ravg,lavg,avg;
        
        // unsigned long long sum=accumulate(nums.begin(),nums.end(),0);
        unsigned long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum=sum+nums[i];
        }
        // cout<<sum<<endl;
        
        for(int i=0; i<n; i++)
        {
            lsum=lsum+nums[i];
            rsum=sum-lsum;
            
            lavg=lsum/(i+1);
            ravg=n-i-1==0?0:rsum/(n-i-1);
            avg=abs(lavg-ravg);
            
            if(minim>avg)
            {
                minim=avg;
                minIndex=i;
            }
        }
        
        return minIndex;
    }
};