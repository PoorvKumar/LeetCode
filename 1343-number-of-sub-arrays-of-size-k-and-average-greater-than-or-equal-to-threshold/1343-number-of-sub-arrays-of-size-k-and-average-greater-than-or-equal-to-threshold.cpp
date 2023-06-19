class Solution 
{
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int sum=0;
        for(int i=0; i<k; i++)
        {
            sum=sum+arr[i];
        }
        
        int ans=0;
        if(sum/k>=threshold)
        {
            ans++;
        }
        
        int n=arr.size();
        int i=1;
        
        while(i<=n-k)
        {
            sum=sum+arr[i+k-1];
            sum=sum-arr[i-1];
            
            if(sum/k>=threshold)
            {
                ans++;
            }
            
            i++;
        }
        
        return ans;
    }
};