class Solution 
{
private:
    unordered_map<int,string> umap;
    
    string convertToTitleUtil(int n)
    {
        if(umap.count(n))
        {
            return umap[n];
        }
        
        int val=n/26;
        int z=n%26;
        
        if(z==0)
        {
            val--;
        }
        
        string s=val>0?convertToTitleUtil(val):"";
        s=s+umap[z];
        
        return s;
    }
public:
    string convertToTitle(int columnNumber) 
    {
        umap[0]="Z";
        
        for(int i=1; i<26; i++)
        {
            umap[i]='A'+i-1;
        }
        
        return convertToTitleUtil(columnNumber);
    }
};