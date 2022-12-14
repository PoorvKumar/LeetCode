class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> umap;
        int maxim=0;
        string substr="";
        int j=0;
        
        for(int i=0; i<s.length(); i++)
        {
            if(umap.count(s[i])==0)
            {
                substr=substr+s[i];
                umap[s[i]]=j++;
            }
            else
            {
                int x=substr.length();
                maxim=max(maxim,x);
                
                // substr.erase(substr.begin(),substr.begin()+umap[s[i]]+1);
                for(int j=0; j<umap[s[i]]+1; j++)
                {
                    umap.erase(substr[0]);
                    substr.erase(substr.begin());
                }
                substr=substr+s[i];
                j=substr.length();
                umap[s[i]]=j++;
            }
        }
        
        // cout<<substr<<endl;
        int x=substr.length();
        maxim=max(maxim,x);
        return maxim;
    }
};