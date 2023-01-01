class Solution 
{
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char,string> umap;
        
        stringstream ss;
        ss<<s;
        
        string str;
        int i=0;
        
        while(ss>>str) //check if follows pattern
        {
            if(!umap.count(pattern[i]))
            {
                umap[pattern[i]]=str;
            }
            else if(str.compare(umap[pattern[i]])!=0)
            {
                return false;
            }
            i++;
        }
        
        if(i!=pattern.length())
        {
            return false;
        }
        
        unordered_set<string> uset; //check if all keys have unique values;
        for(auto x:umap)
        {
            uset.insert(x.second);
        }
        
        return umap.size()==uset.size();
        
        // return true;
    }
};