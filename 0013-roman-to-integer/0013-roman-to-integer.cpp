class Solution 
{
private:
    unordered_map<char,int> umap;
    
    int romanToIntUtil(string& s,int index)
    {
        if(index==s.length()-1)
        {
            return umap[s[index]];
        }
        
        if(index>=s.length())
        {
            return 0;
        }
        
        if(umap[s[index]]<umap[s[index+1]])
        {
            int val=umap[s[index+1]]-umap[s[index]];
            val=val+romanToIntUtil(s,index+2);
            return val;
        }
        
        int val=umap[s[index]]+romanToIntUtil(s,index+1);
        return val;
    }
public:
    int romanToInt(string s) 
    {
        umap['I']=1;
        umap['V']=5;
        umap['X']=10;
        umap['L']=50;
        umap['C']=100;
        umap['D']=500;
        umap['M']=1000;
        
        return romanToIntUtil(s,0);
    }
};