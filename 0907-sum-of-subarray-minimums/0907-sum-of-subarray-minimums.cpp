class Solution 
{
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n=arr.size();
        
        vector<int> right(n,n);
        vector<int> left(n,-1);
        
        stack<pair<int,int>> stk;
        
        // nse index to the right
        for(int i=0; i<n; i++)
        {
            while(!stk.empty() && stk.top().first>arr[i]) //element at ith index will be minimum even if same element at higher index
            {
                right[stk.top().second]=i;
                stk.pop();
            }
            stk.push({arr[i],i});
        }
        
        while(!stk.empty())
        {
            stk.pop();
        }
        
        // nse index to the left which needs to be unique
        for(int i=n-1; i>=0; i--)
        {
            while(!stk.empty() && stk.top().first>=arr[i]) //element at ith index will not be minimum when same at lower index
            {
                left[stk.top().second]=i;
                stk.pop();
            }
            stk.push({arr[i],i});
        }
        
        long long ans=0;
        unsigned long long M=1e9+7;
        
        for(int i=0; i<n; i++)
        {
            long long val=(((i-left[i])%M*(right[i]-i)%M)%M*arr[i]%M)%M; //number of subarrays the element is minimum * elem
            ans=(ans%M+val%M)%M;
        }
        
        // ans=ans%M;
        ans%=M;
        
        return ans; // Montonic Stack Problem
        //TC: O(n)
        //SC: O(2*n)
    }
};