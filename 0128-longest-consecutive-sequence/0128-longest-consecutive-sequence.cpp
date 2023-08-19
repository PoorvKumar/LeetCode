class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> st;
        
        for(auto x:nums)
        {
            st.insert(x);
        }
        
        int ans=0;
        
        for(auto it=st.begin(); it!=st.end(); it++)
        {
            int j=1;
            
            auto nit=++it;
            it--;
            
            while(nit!=st.end() && *nit-j==*it)
            {
                j++;
                nit++;
            }
            
            ans=max(ans,j);
            
            it=prev(nit);
        }
        
        return ans;
    }
};