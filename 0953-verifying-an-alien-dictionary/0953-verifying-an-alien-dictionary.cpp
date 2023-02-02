class Solution 
{
private:
    unordered_map<char,int> umap;
    
    bool checkLexicographic(string& s1,string& s2)
    {
        int i=0;
        int n1=s1.length();
        int n2=s2.length();
        
        while(i<n1 && i<n2 && s1[i]==s2[i])
        {
            i++;
        }
        
        if(i>=n2 && i<n1)
        {
            return false;
        }
        
        if(i>=n1)
        {
            return true;
        }
        
        if(umap[s1[i]]<=umap[s2[i]])
        {
            return true;
        }
        
        return false;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        // unordered_map<char,int> umap;
        for(int i=0; i<order.size(); i++)
        {
            umap[order[i]]=i;
        }
        
        for(int i=1; i<words.size(); i++)
        {
            if(!checkLexicographic(words[i-1],words[i]))
            {
                return false;
            }
        }
        
        return true;
    }
};