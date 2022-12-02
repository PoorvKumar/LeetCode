class Solution 
{
private:
    unordered_map<char,vector<string>> umap;
    
public:
    Solution()
    {
        umap['2']=vector<string>({"a","b","c"});
        umap['3']=vector<string>({"d","e","f"});
        umap['4']=vector<string>({"g","h","i"});
        umap['5']=vector<string>({"j","k","l"});
        umap['6']=vector<string>({"m","n","o"});
        umap['7']=vector<string>({"p","q","r","s"});
        umap['8']=vector<string>({"t","u","v"});
        umap['9']=vector<string>({"w","x","y","z"});
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if(digits.length()==0)
        {
            return vector<string>();
        }
        if(digits.length()==1)
        {
            return umap[digits[0]];
        }
        
        vector<string> vec=umap[digits[0]];
        digits=digits.substr(1,digits.length()-1);
        vector<string> subres=letterCombinations(digits);
        
        vector<string> ans;
        
        for(int i=0; i<vec.size(); i++)
        {
            // string str=vec[i];
            for(int j=0; j<subres.size(); j++)
            {
                // str=str+subres[j];
                // ans.push_back(str);
                ans.push_back(vec[i]+subres[j]);
            }
        }
        
        return ans;
    }
};