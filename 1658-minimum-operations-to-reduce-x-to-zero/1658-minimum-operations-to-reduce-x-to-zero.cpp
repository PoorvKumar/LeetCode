class Solution 
{
public:
    int minOperations(vector<int>& nums, int target) 
    {
        vector<int> prefix;
        int sum=0;
        
        int S=accumulate(nums.begin(),nums.end(),0);
        if(S<target)
        {
            return -1;
        }
        
        for(auto x:nums)
        {
            sum=sum+x;
            if(sum>target)
            {
                break;
            }
            prefix.push_back(sum);
        }
        
        vector<int> suffix;
        sum=0;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            sum=sum+nums[i];
            if(sum>target)
            {
                break;
            }
            
            suffix.push_back(sum);
        }
        
//         for(auto x:prefix)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         for(auto x:suffix)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
        int ans=INT_MAX;
        
        for(int i=0; i<prefix.size(); i++)
        {
            if(prefix[i]==target)
            {
                ans=min(ans,i+1);
                break;
            }
            
            int val=target-prefix[i];
            if(val>0)
            {
                int j=lower_bound(suffix.begin(),end(suffix),val)-suffix.begin();
                // cout<<val<<" "<<j<<" prefix\n";
                if(j<suffix.size() && suffix[j]==val)
                {
                    ans=min(ans,i+1+j+1);
                }
            }
            
        }
        
        for(int i=0; i<suffix.size(); i++)
        {
            if(suffix[i]==target)
            {
                ans=min(ans,i+1);
                break;
            }
            
            int val=target-suffix[i];
            if(val>0)
            {
                int j=lower_bound(prefix.begin(),end(prefix),val)-prefix.begin();
                // cout<<val<<" "<<j<<" suffix\n";
                if(j<prefix.size() && prefix[j]==val)
                {
                    ans=min(ans,i+1+j+1);
                }
            }
        }
        
        return ans<INT_MAX?ans:-1; 
        //TC: O(nlogn)
        //SC: O(n)+O(n)
    }
};