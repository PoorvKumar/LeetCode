class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> umap;
        int ans=0;
        int low=0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(umap.count(s[i]) && umap[s[i]]>=low) //char present in substring after low
            {
                ans=max(ans,i-low);
                low=umap[s[i]]+1;
                // umap[s[i]]=i;
            }
            // else
            // {
            //     umap[s[i]]=i;
            // }
            umap[s[i]]=i;
        }
        
        int n=s.length();
        ans=max(ans,n-low); //when i becomes equal to n
        
        return ans;
    }
};